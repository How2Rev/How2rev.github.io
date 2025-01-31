
import struct
import ctypes

from unicorn import *
from unicorn.x86_const import *
from capstone import Cs, CS_ARCH_X86, CS_MODE_64
import sys
import signal
mu = None

def handler(sig, frame):
    mu.emu_stop()


signal.signal(signal.SIGINT, handler)
import binascii

COFF_MAGIC_HEADER = 0xC0FFC0FF
SHELLCODE_OFFSET = 0x90


def hook_code(uc, address, size, user_data):
    instr_bytes = uc.mem_read(address, size)

    md = Cs(CS_ARCH_X86, CS_MODE_64)
    for insn in md.disasm(instr_bytes, address):
        print(">>> Tracing instruction at 0x%x: %s %s" % (insn.address, insn.mnemonic, insn.op_str))
        if insn.mnemonic == 'syscall':
            rsp = mu.reg_read(UC_X86_REG_RSP)
            stack = bytes(mu.mem_read(rsp, 32))
            print(stack)

    if address == 0x8040020: #syscall_exit()
        uc.emu_stop()

def emulate_code(shellcode, context):
    global mu
    mu = Uc(UC_ARCH_X86, UC_MODE_64)

    ADDRESS = 0x08040000
    mu.mem_map(ADDRESS, 0x1000)
    mu.mem_write(ADDRESS, shellcode)

    mu.reg_write(UC_X86_REG_RSP, ADDRESS + 0x100)

    rdi = context.get("rdi")
    assert(rdi)

    rax = context.get("rax")
    assert(rax)
    mu.reg_write(UC_X86_REG_RAX, rax)
    mu.reg_write(UC_X86_REG_RDI, rdi)

    mu.hook_add(UC_HOOK_CODE, hook_code)

    mu.emu_start(ADDRESS, ADDRESS + len(shellcode))

    print("Done emulation")

def main():
    with open("programm.coff", "rb") as file:
        buffer = file.read()

    pos = 0
    magic_header = struct.unpack('<I', buffer[:pos+4])[0]
    if magic_header != COFF_MAGIC_HEADER:
        raise ValueError("Invalid COFF magic header")

    pos +=4
    coff_need_decrypt = struct.unpack('<B', buffer[pos:pos+1])[0]
    
    print(f"COFF_ENCRYPT_SHELLCODE : {coff_need_decrypt}")
    pos += 1

    rax = struct.unpack('<Q', buffer[pos:pos+8])[0]
    print(f"COFF_RAX_SET : {hex(rax)}")
    pos += 8

    rdi = struct.unpack('<Q', buffer[pos:pos+8])[0]
    print(f"COFF_RDI_SET : {hex(rdi)}")
    pos += 8
    
    XOR_KEY = buffer[pos:pos+16]
    pos +=16   
    
    pos +=3 #skip padding

    shellcode = buffer[pos:]
    if coff_need_decrypt:
        shellcode =  bytes(a ^ b for a, b in zip(shellcode, XOR_KEY*len(shellcode)))

    context = {}
    context["rdi"] = rdi
    context["rax"] = rax

    emulate_code(shellcode, context)



if __name__ == "__main__":
    main()

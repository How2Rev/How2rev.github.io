from time import sleep
import random
import struct

random.seed(0xdeadbeef)

XOR_KEY = random.randbytes(16)

#char shellcode[] = "\xeb\x20\x48\x31\xc0\x48\x31\xff\x48\x31\xf6\x48\x31\xd2\xb0\x01\x40\xb7\x01\x5e\xb2\x0c\x0f\x05\x48\x31\xc0\xb0\x3c\x40\xb7\x00\x0f\x05\xe8\xdb\xff\xff\xff\x48\x65\x6c\x6c\x6f\x20\x57\x6f\x72\x6c\x64\x21";

COFF_MAGIC_HEADER = 0xC0FFC0FF
#SHELLCODE_HELLO_WORLD= b"\xeb\x20\x48\x31\xc0\x48\x31\xff\x48\x31\xf6\x48\x31\xd2\xb0\x01\x40\xb7\x01\x5e\xb2\x0c\x0f\x05\x48\x31\xc0\xb0\x3c\x40\xb7\x00\x0f\x05\xe8\xdb\xff\xff\xff\x48\x65\x6c\x6c\x6f\x20\x57\x6f\x72\x6c\x64\x21"

SHELLCODE= open("shellcode-gen/shellcode.bin","rb").read()

encrypted = bytearray(a ^ b for a, b in zip(SHELLCODE, XOR_KEY*len(SHELLCODE)))
assert(len(encrypted) == len(SHELLCODE))

# COFF structure
coff_struct = struct.pack('<I', COFF_MAGIC_HEADER)  # COFF_MAGIC_HEADER (4bytes)
coff_struct += struct.pack('B', 1)  # COFF_ENCRYPT_SHELLCODE (1 byte)
coff_struct += struct.pack('<Q', 0x432867435E12FF43)  # COFF_SET_VM_REG_RAX (8bytes)
coff_struct += struct.pack('<Q', 0XF256394BF0A19F44)  # COFF_SET_VM_REG_RDI (8bytes)
coff_struct += XOR_KEY #COFF XOR KEY
coff_struct += b'\x00' * 3 # PAD
coff_struct += encrypted  #shellcode

# Write the COFF file
with open("programm.coff", "wb") as file:
    file.write(coff_struct)

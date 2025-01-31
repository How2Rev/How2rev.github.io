import os
import subprocess
from time import sleep

SHELLCODE_FILE = "keygen.asm"

if os.path.exists("shellcode.o"):
    os.remove("shellcode.o")

if os.path.exists("shellcode"):
    os.remove("shellcode")


cmd = f"nasm -f elf64 {SHELLCODE_FILE} -o shellcode.o"
subprocess.Popen(cmd,shell=True)

sleep(0.5)

cmd = f"ld shellcode.o -o shellcode"
subprocess.Popen(cmd,shell=True)

print("Done generating shellcode")

sleep(0.5)

cmd = "objcopy -O binary -j '.text' shellcode.o shellcode.bin"
subprocess.Popen(cmd,shell=True)

print("Done generating shellcode bin")

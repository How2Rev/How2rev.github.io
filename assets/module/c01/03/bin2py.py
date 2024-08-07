import subprocess
import sys
import os
import re
import argparse
import lief

def pad(hex):
    if len(hex) % 2 == 0:
        return hex
    else:
        return "0" + hex
    
def parse_file(filename):
    fd = open(filename, "rb")
    fd.close()
    bin = lief.parse(filename)
    text = bin.get_section(".text")
    code_raw = ""
    for byte in text.content:
        code_raw += "\\x{0}".format(pad(hex(byte).replace("0x","")))
    return code_raw.encode(),text.content
   

def check_file_type(filename):
    if not os.path.isfile(filename):
        print("File not found: " + filename)
        sys.exit(1)  

def print_usage():
    print("Usage : python3 bin2py.py --file compiled_shellcode --format 1 => will output 1 line of python3 binary shellcode")
    print("Usage : python3 bin2py.py --file compiled_shellcode --format dword => will out dword line of python3 binary shellcode")


if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Options for ELF x64 binary')
    parser.add_argument('--file',help='binary to use for shellcode generation')
    #parser.add_argument('--format', required=False, default='1', help='outut format : [1, dword, qword]') #todo

    args = parser.parse_args()

    if args.file is None:
        print_usage()
    
    else:

        check_file_type(args.file)
        code,text = parse_file(args.file)
        print("-------------------------------------\n")
        print(f"Your shellcode : {code.decode()}")
        print("-------------------------------------\n")
        print("payload = b\"\"")
        print(f"payload += b\"{code.decode()}\"")

        with open("shellcode.bin","wb") as fd:
            fd.write(text)
        
    

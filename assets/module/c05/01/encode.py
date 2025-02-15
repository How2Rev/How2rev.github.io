with open("flag","r") as fd:
    flag = fd.read()
    fd.close()
    
KEY1=0x43
KEY2=0x23
KEY3=0xF4

fd= open("flag.enc","wb")

buf = b""
for i in range(0, len(flag), 3):
    
        buf += (ord(flag[i]) ^ KEY1).to_bytes(1, byteorder='big')
        buf += (ord(flag[i+1]) ^ KEY2).to_bytes(1, byteorder='big')
        buf += (ord(flag[i+2]) ^ KEY3).to_bytes(1, byteorder='big')
    
fd.write(buf)
fd.close()

with open("flag.enc","rb") as fd:
    flagenc = fd.read()
    fd.close()
    
buf = ""
for i in range(0, len(flag), 3):

    buf += chr(flagenc[i] ^ KEY1)
    buf += chr(flagenc[i+1] ^ KEY2)
    buf += chr(flagenc[i+2] ^ KEY3)
        

print(buf)

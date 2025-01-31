import binascii
import array

flag = "LRCTF{Bas1c_LoAD3r_Ex3cution!!!" + '}'
print(len(flag))

KEY1 = 0x432867435E12FF43 
KEY2 = 0XF256394BF0A19F44

flag_1 = flag[0:8].encode()
r  = binascii.hexlify(flag_1)

swap = b''
for i in range(0, len(r), 2):
    swap += r[len(r)-i-2:len(r)-i]

FLAG1 = 0x61427b465443524c

print(hex(KEY1 ^ FLAG1))

flag_1 = flag[8:16].encode()
r  = binascii.hexlify(flag_1)

swap = b''
for i in range(0, len(r), 2):
    swap += r[len(r)-i-2:len(r)-i]

FLAG1 = 0x44416f4c5f633173
print(hex(KEY2 ^ FLAG1))

flag_1 = flag[16:24].encode()
r  = binascii.hexlify(flag_1)

swap = b''
for i in range(0, len(r), 2):
    swap += r[len(r)-i-2:len(r)-i]

FLAG1 = 0x75633378455f7233
print(hex(KEY1 ^ FLAG1))

flag_1 = flag[24:].encode()
r  = binascii.hexlify(flag_1)

swap = b''
for i in range(0, len(r), 2):
    swap += r[len(r)-i-2:len(r)-i]

FLAG1 = 0x7d2121216e6f6974
print(hex(KEY2 ^ FLAG1))


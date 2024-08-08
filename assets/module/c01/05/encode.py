
flag = b"LRCTF{Hidd3n_C0d3_a34ff}"
assert(len(flag) % 8 ==0)

flag_p1 = flag[0:8]
flag_p2 = flag[8:16]
flag_p3 = flag[16:24]

key1 = 8 #sigpfe signal
key2 = b"ELF_GNUX"

p1_xored = int.from_bytes(flag_p1, byteorder="little") ^key1
print(hex(p1_xored))

p2_xored = [0]*8
for i in range(8):
    p2_xored[i] = flag_p2[i] ^ key2[i]

print(p2_xored)


print(hex(int.from_bytes(flag_p3, byteorder="little")))
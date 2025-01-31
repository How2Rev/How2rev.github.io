import random
r = []

seq = {
    0 : 'W',
    1 : 'A',
    2 : 'S',
    3 : 'D'
}

flag = ""    
for i in range(32):
    z = random.randint(0,3)
    r.append(z)
    flag += seq[z]
    

print(r)
print(flag)

#DASASWWWAWASAAWWDAWASSDSDDAAADSS


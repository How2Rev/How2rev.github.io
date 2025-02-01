flag = "LRCTF" + "{IntroDuc1oN_to_CrypT0!}"

print(len(flag))
from Crypto.Cipher import ChaCha20
from Crypto.Random import get_random_bytes
import binascii


key = "483a3cea21db18923b6bf5b5dc71243ec54a44bd09954152609ace1d483091d8"
nonce = b"\xde\xad\xbe\xef\xc0\xfe\xba\xb1"
keyb = binascii.unhexlify(key)

print("KEY = ", key)

v_format = []
for i in range(32):
    v_format.append(keyb[i])

print(v_format)


ciphertext = binascii.unhexlify("872dd339c531052a8bbbe4eab19a1413d618e9a97d2931492cc04aa446")


v_format = []
for i in range(len(flag)):
    v_format.append(ciphertext[i])

print(v_format)

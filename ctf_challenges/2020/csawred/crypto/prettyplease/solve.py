from base64 import b64decode
from base64 import b64encode

def byte_xor(ba1, ba2):
    return bytes([_a ^ _b for _a, _b in zip(ba1, ba2)])

x = input()

iv_and_ct = b64decode(x)
iv = iv_and_ct[:16]
ct = iv_and_ct[16:]

key = byte_xor(ct, b'Your application has been REJECTED')

correct_pt = b'Your application has been ACCEPTED'
print(b64encode(iv + byte_xor(key, correct_pt)))
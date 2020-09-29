#!/usr/bin/env python3
from base64 import b64decode

"""
Don't worry, if you break out of this one, we have another one underneath so that you won't
wreak any havoc!
"""

print("EduPy 3.8.2")


the_file = open("sandbox.py", "r")
some_number = int(((54 * 8) / 16) * (1/3) - 8)
a_certain_line_of_code = the_file.readlines()[some_number].strip().split(" ")
base64 = a_certain_line_of_code[some_number]
b64decode = a_certain_line_of_code[-some_number]
print(some_number)
print(base64)
print(b64decode)
the_file.close()
b64decode = getattr(__import__(base64), b64decode)
RMbPOQHCzt = __builtins__.__dict__[__import__](numpy)
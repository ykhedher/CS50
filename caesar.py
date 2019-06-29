from sys import argv
from cs50 import get_string
# case the number of arguments is not 2 
if len(argv) != 2:
    print("Usage: python caesar.py key: ")
# convert key to int    
key = int(argv[1])
# prompt the user for a string
string = get_string("Plaintext: ")
# declare the output variable
output = ""
for c in string:
    if c.isalpha():
        if c.isupper():
            c = (((ord(c) - ord('A')) + key) % 26) + ord('A')
            output += chr(c)
        else:
            c = (((ord(c) - ord('a')) + key) % 26) + ord('a')
            output += chr(c)
    else:
        output += c
print("ciphertext:", output)
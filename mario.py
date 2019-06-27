# importing get_int function from cs50 library
from cs50 import get_int

# prompt user for input until he type it correctly (1-8)
while True:
    n = get_int("Height: ")
    if n < 9 and n > 0:
        break
# main for loop
for i in range(n):
    # this loop prints spaces
    for k in range(n-i-1):
        print(" ", end="")
    # this loop print #
    for j in range(i+1):
        print("#", end="")
    # this to print a newline
    print("")
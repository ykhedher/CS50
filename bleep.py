from cs50 import get_string
from sys import argv


def main():
    # case the number of arguments is not 2 
    if len(argv) != 2:
        sys.exit(1)
        print("Usage: python bleep.py dictionary")
    # open the text file and load it in a set
    my_set = set(open(argv[1]).read().split())
    # prompt user for message
    message = get_string("What message would you like to censor?\n")
    # split the message
    list = message.split()
    for w in list:
        if w.lower() in my_set:
            print("*" * len(w), end=" ")
        else:
            print(w, end=" ")
    print()
    
    
if __name__ == "__main__":
    main()

from cs50 import get_float

# ask the user for input b
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break
# converting dollars to cents
dollar = int(change) * 100
cents = dollar // 25
change = (change - int(change)) * 100

# number of cents
x1 = int(change) // 25
change = int(change) % 25
# number of 10
x2 = int(change) // 10
change = int(change) % 10
# number of 5
x3 = int(change) // 5
change = int(change) % 5
# number of 1
x4 = int(change) // 1
# print the total 
print(cents + x1 + x2 + x3 + x4)


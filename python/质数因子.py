import math
num = int(input())
s = ''
prime = 2
while prime < math.sqrt(num)+1:
    if num%prime != 0:
        prime += 1
    else:
        num = num //prime
        s += str(prime)+' '
        prime = 2
if num>=2:
    s += str(num)+' '
print(s)

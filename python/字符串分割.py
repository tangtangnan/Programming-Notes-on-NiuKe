import sys

input_str = input()

while len(input_str):
    if len(input_str)>=8:
        print(input_str[:8])
        input_str = input_str[8:]
    else:
        print(input_str+'0'*(8-len(input_str)))
        input_str = []

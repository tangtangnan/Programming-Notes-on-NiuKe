'''
python将16进制转为10进制可以用int('hex型',16) 八进制转十进制int('八进制型',8) 八进制或十六进制或10进制装二进制直接调用 bin(任意进制) 
'''
while True:
    try:
        s=input()
        print(int(s,16))
    except:
        break
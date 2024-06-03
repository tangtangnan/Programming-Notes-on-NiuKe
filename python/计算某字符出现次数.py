String_1 = input()  #输入待查找的字符串
String_1 = String_1.upper() #全部取大写（题目不区分大小写）
list_1 = list(String_1) #每一个字符都做为列表的一项
check = input() #查找的字符
check = check.upper()#同样变为大写
num = 0
for word in list_1:#遍历并查找
    if word == check:
        num = num + 1
print(num)

def isValid(s):
    dic = {')':'(',']':'[','}':'{'}  
    stack = []  

    for i in s:  
        if i in dic:  
            top_element = stack.pop() if stack else '#'
            if top_element != dic[i]:   
                return False  
        else:   
            stack.append(i)  

    return not stack

print(isValid("([])"))

#给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
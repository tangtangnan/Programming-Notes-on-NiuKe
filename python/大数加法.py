class Solution:
    def solve(self , s , t ):
        # write code here
        return int(s)+int(t);


# 获取用户输入  
s = input("请输入第一个整数（以字符串形式）：")  
t = input("请输入第二个整数（以字符串形式）：") 


solution = Solution()  
result = solution.solve(s, t)  
print(result)
import re #导入正则表达式模块
class Solution:
    def solve(self , IP: str) -> str:
         #正则表达式限制0-255 且没有前缀0 四组齐全
        ipv4 = "^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$"
        #ipv4 = "(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])"
        #正则表达式限制出现8组，0-9a-fA-F的数，个数必须是1-4个
        ipv6 = "([0-9a-fA-F]{1,4}\:){7}([0-9a-fA-F]{1,4})$"
        ipv4 = re.compile(ipv4)
        ipv6 = re.compile(ipv6)
        #调用正则匹配函数
        if ipv4.match(IP): 
            return "IPv4"
        elif ipv6.match(IP):
            return "IPv6"
        else:
            return "Neither"

# 创建 Solution 类的实例  
solution = Solution()  
  
# 调用 solve 方法进行 IP 地址验证  
IP = "172.16.254.010"  # 示例 IP 地址   IPv4这个规则不够严格
result = solution.solve(IP)  
print(result)  # 输出验证结果
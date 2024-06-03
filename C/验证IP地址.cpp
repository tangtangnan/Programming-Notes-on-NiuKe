#include<iostream>
#include<cmath>
#include<string>
#include <regex>    //使用regex需要包含此头文件

using namespace std;

class Solution 
{
public:
    string solve(string IP) 
    {
        //定义IPv4的匹配方法
        regex IPv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        // 定义IPv6的匹配方法
        regex IPv6("(([0-9a-fA-F]{1,4})\\:){7}([0-9a-fA-F]{1,4})");
        // 使用regex_match方法匹配字符串
        if (regex_match(IP, IPv4)) {    // 匹配IPv4
            return "IPv4";
        }
        else if (regex_match(IP, IPv6)) {    // 匹配IPv6
            return "IPv6";
        }
        return "Neither";    // 都没匹配成功
    }
};

int mai3n()
{
    Solution a;
    string sbl = a.solve("192.068.1.1");
    cout << sbl << endl;
    return 0;
}
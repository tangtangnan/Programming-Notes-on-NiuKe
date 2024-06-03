#include<iostream>
#include<cmath>
#include<string>
#include <regex>    //ʹ��regex��Ҫ������ͷ�ļ�

using namespace std;

class Solution 
{
public:
    string solve(string IP) 
    {
        //����IPv4��ƥ�䷽��
        regex IPv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        // ����IPv6��ƥ�䷽��
        regex IPv6("(([0-9a-fA-F]{1,4})\\:){7}([0-9a-fA-F]{1,4})");
        // ʹ��regex_match����ƥ���ַ���
        if (regex_match(IP, IPv4)) {    // ƥ��IPv4
            return "IPv4";
        }
        else if (regex_match(IP, IPv6)) {    // ƥ��IPv6
            return "IPv6";
        }
        return "Neither";    // ��ûƥ��ɹ�
    }
};

int mai3n()
{
    Solution a;
    string sbl = a.solve("192.068.1.1");
    cout << sbl << endl;
    return 0;
}
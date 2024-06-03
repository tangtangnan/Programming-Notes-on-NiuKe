#include <iostream>
#include <string>
using namespace std;

int main123()
{
    string str;
    while (cin >> str)
    {
        // 补0
        int len = str.size();
        if (len % 8 != 0)
        {
            int count = 8 - len % 8;
            str.append(count, '0');//拼接字符串
        }

        // 按格式输出
        int newLen = str.size();
        for (int i = 0; i < newLen; i += 8)
        {
            cout << str.substr(i, 8) << endl;
        }
        break;
    }
    return 0;
}
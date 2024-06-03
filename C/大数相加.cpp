#include<iostream>
#include<cmath>
#include<string>

using namespace std;


class Solution {
public:
    string solve(string s, string t) 
    {
        //若是其中一个为空，返回另一个
        if (s.empty())
            return t;
        if (t.empty())
            return s;
        //让s为较长的，t为较短的
        if (s.length() < t.length())
        {
            swap(s, t);
        }

        //进位标志
        int carry = 0;
        //从后往前遍历较长的字符串
        for (int i = s.length() - 1; i >= 0; i--) 
        {
            //转数字加上进位
            int temp = s[i] - '0' + carry;
            //转较短的字符串相应的从后往前的下标
            int j = i - s.length() + t.length();

            //如果较短字符串还有
            if (j >= 0)
            {
                //转数组相加
                temp += t[j] - '0';
            }
            //取进位
            carry = temp / 10;
            //去十位
            temp = temp % 10;
            //修改结果
            s[i] = temp + '0';
        }
        //最后的进位
        if (carry == 1)
        {
            s = '1' + s;
        }
        return s;
    }
};

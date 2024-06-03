#include<iostream>
#include<cmath>
#include<string>

using namespace std;


class Solution {
public:
    string solve(string s, string t) 
    {
        //��������һ��Ϊ�գ�������һ��
        if (s.empty())
            return t;
        if (t.empty())
            return s;
        //��sΪ�ϳ��ģ�tΪ�϶̵�
        if (s.length() < t.length())
        {
            swap(s, t);
        }

        //��λ��־
        int carry = 0;
        //�Ӻ���ǰ�����ϳ����ַ���
        for (int i = s.length() - 1; i >= 0; i--) 
        {
            //ת���ּ��Ͻ�λ
            int temp = s[i] - '0' + carry;
            //ת�϶̵��ַ�����Ӧ�ĴӺ���ǰ���±�
            int j = i - s.length() + t.length();

            //����϶��ַ�������
            if (j >= 0)
            {
                //ת�������
                temp += t[j] - '0';
            }
            //ȡ��λ
            carry = temp / 10;
            //ȥʮλ
            temp = temp % 10;
            //�޸Ľ��
            s[i] = temp + '0';
        }
        //���Ľ�λ
        if (carry == 1)
        {
            s = '1' + s;
        }
        return s;
    }
};

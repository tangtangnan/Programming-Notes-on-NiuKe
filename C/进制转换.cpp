#include<iostream>
#include<string>
#include <ctype.h>
using namespace std;

int main321()
{
    string s;
    int ten, tran;
    while (cin >> s)
    {
        ten = 0;//��ʼֵΪ0
        for (int i = 2; i < s.size(); i++)
        {
            //��ʮ�����Ƶ��ַ�ת��Ϊʮ��������
            if ('0' <= s[i] && s[i] <= '9')
            {
                tran = s[i] - '0';
            }
            else 
            {
                if (islower(s[i]))
                {
                    s[i] = toupper(s[i]);
                }
                tran = s[i] - 'A' + 10;
            }

            ten = ten * 16 + tran;//���ϵ���
        }
        cout << ten << endl;
    }
    return 0;
}


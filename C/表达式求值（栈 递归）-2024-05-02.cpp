#include<iostream>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
using namespace std;


class Solution 
{
public:
    vector<int> function(string s, int index) 
    {
        stack<int> stack;
        int num = 0;
        char op = '+';
        int i;
        for (i = index; i < s.length(); i++)
        {
            //����ת����int����
            if (isdigit(s[i]))  //�����ж��ַ����ַ����Ƿ�������1-9
            {
                num = num * 10 + s[i] - '0';
                if (i != s.length() - 1)
                    continue;
            }

            //����'('ʱ�������������ڵĵ���һ�����ִ���
            if (s[i] == '(') 
            {
                //�ݹ鴦������
                vector<int> res = function(s, i + 1);
                num = res[0];
                i = res[1];
                if (i != s.length() - 1)
                    continue;
            }
            switch (op) 
            {
                    //�Ӽ�������ջ
                case '+':
                    stack.push(num);
                    break;
                case '-':
                    //�෴��
                    stack.push(-num);
                    break;
                    //���ȼ���˺�
                case '*':
                    int temp = stack.top();
                    stack.pop();
                    stack.push(temp * num);
                    break;
            }
            num = 0;
            //�����Ž����ݹ�
            if (s[i] == ')')
                break;
            else
                op = s[i];
        }
        int sum = 0;
        //ջ��Ԫ�����
        while (!stack.empty()) 
        {
            sum += stack.top();
            stack.pop();
        }
        return vector<int> {sum, i};
    }

    int solve(string s) 
    {
        return function(s, 0)[0];
    }
};

int main609()
{
    string ss = "30-8"; //"(2*(3-4))*5"

    Solution sl;

    int ret = sl.solve(ss);
    cout << "Current median: " << ret << endl; 

    return 0;
}


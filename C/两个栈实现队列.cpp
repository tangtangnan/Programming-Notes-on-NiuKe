#include<iostream>
#include<cmath>
#include<stack>
using namespace std;


class Solution
{
public:
    //����о�������ջ
    void push(int node) 
    {
        stack1.push(node);
    }

    int pop() {
        //����һ��ջ�����ݵ�������ڶ���ջ��
        while (!stack1.empty()) 
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        //�ڶ���ջջ���������Ƚ�����Ԫ�أ�������
        int res = stack2.top();
        stack2.pop();
        //�ٽ��ڶ���ջ��Ԫ�طŻص�һ��ջ
        /*while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        */
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


int main098()
{
    // ��ջʵ�ֶ���
    int values[] = 
    {
       1,2,3,4,5
    };
    Solution sol;
    for (int val : values) 
    {
        sol.push(val);
    }
    for (int value : values) 
    {
        //EXPECT_EQ(value, sol.pop());
        cout << sol.pop() << "\n";
    }
    return 0;
}

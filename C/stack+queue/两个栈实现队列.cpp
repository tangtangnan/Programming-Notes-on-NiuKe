#include<iostream>
#include<cmath>
#include<stack>
using namespace std;


class Solution
{
public:
    //入队列就正常入栈
    void push(int node) 
    {
        stack1.push(node);
    }

    int pop() {
        //将第一个栈中内容弹出放入第二个栈中
        while (!stack1.empty()) 
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        //第二个栈栈顶就是最先进来的元素，即队首
        int res = stack2.top();
        stack2.pop();
        //再将第二个栈的元素放回第一个栈
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
    // 用栈实现队列
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

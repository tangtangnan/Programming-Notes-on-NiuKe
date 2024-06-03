#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

class Solution {
public:
    /**
     *
     * @param s string×Ö·û´®
     * @return bool²¼¶ûÐÍ
     */
    bool isValid(string s) {
        // write code here
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if ('(' == s[i])
            {
                st.push(')');
            }
            else if ('[' == s[i])
            {
                st.push(']');
            }
            else if ('{' == s[i])
            {
                st.push('}');
            }
            else if (st.empty())
            {
                return false;
            }
            else if (s[i] == st.top())
            {
                st.pop();
            }
        }

        return st.empty();
    }
};

int main543()
{
    Solution a;
    bool bl = a.isValid("{[[]]}");
    cout << (bl ? "Valid" : "Invalid") << endl;
    return 0;
}
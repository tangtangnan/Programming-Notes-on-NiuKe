#include<iostream>
#include<cmath>
//#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        //窗口大于数组长度的时候，返回空
        if (size <= num.size() && size != 0)
            //数组后面要空出窗口大小，避免越界
            for (int i = 0; i <= num.size() - size; i++) {
                //寻找每个窗口最大值
                int max = 0;
                for (int j = i; j < i + size; j++) {
                    if (num[j] > max)
                        max = num[j];
                }
                res.push_back(max);
            }
        return res;
    }
};

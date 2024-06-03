#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int>& num) 
    {
        vector<vector<int> > res;
        int n = num.size();
        //不够三元组
        if (n < 3)
        {
            return res;
        }
        //排序
        sort(num.begin(), num.end());
        for (int i = 0; i < n - 2; i++) 
        {
            if (i != 0 && num[i] == num[i - 1])
            {
                continue;
            }

            //后续的收尾双指针
            int left = i + 1;
            int right = n - 1;
            //设置当前数的负值为目标
            int target = -num[i];
            while (left < right) 
            {
                //双指针指向的二值相加为目标，则可以与num[i]组成0
                if (num[left] + num[right] == target) 
                {
                    res.push_back({ num[i], num[left], num[right] });
                    while (left + 1 < right && num[left] == num[left + 1])
                    {
                        //去重
                        left++;
                    }
                    while (right - 1 > left && num[right] == num[right - 1])
                    {
                        //去重
                        right--;
                    }
                    //双指针向中间收缩
                    left++;
                    right--;
                }
                //双指针指向的二值相加大于目标，右指针向左
                else if (num[left] + num[right] > target)
                {
                    right--;
                }
                //双指针指向的二值相加小于目标，左指针向右
                else
                {
                    left++;
                }
            }
        }
        return res;
    }
};

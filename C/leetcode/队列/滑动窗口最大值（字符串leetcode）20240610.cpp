#include<iostream>
#include<cmath>
//#include<stack>
#include<vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& nums, unsigned int k)
    {
        vector<int> res;
        //窗口大于数组长度的时候，返回空
        if (k <= nums.size() && k != 0)
        {
            //数组后面要空出窗口大小，避免越界
            for (int i = 0; i <= nums.size() - k; i++)
            {
                //寻找每个窗口最大值
                int max = nums[i];
                for (int j = i; j < i + k; j++)
                {
                    if (nums[j] > max)
                        max = nums[j];
                }
                res.push_back(max);
            }
        }
        return res;
    }
};// 时间复杂度=n*k

class Solution1 {
public:
    vector<int> maxInWindows(vector<int>& nums, int k)
    {
        if (k == 0)
            return {};
        vector<int>res;
        deque<size_t>window;
        /*Init K integers in the list*/
        for (size_t i = 0; i < k; i++) {
            while (!window.empty() && nums[i] > nums[window.back()]) 
            {
                window.pop_back();
            }
            window.push_back(i);
        }
        res.push_back(nums[window.front()]);
        /*End of initialization*/
        for (size_t i = k; i < nums.size(); i++)
        {
            if (!window.empty() && window.front() <= i - k) 
            {
                window.pop_front();
            }
            while (!window.empty() && nums[i] > nums[window.back()])
            {
                window.pop_back();
            }
            window.push_back(i);
            res.push_back(nums[window.front()]);
        }
        return res;
    }
}; //时间复杂度=n

int main()
{
    Solution ss;
    Solution1 ss1;
    vector<int> num = {1, -1, -2};
    vector<int> num1 = ss1.maxInWindows(num,1);

    for (const auto& row : num1)
    {
        std::cout << row << std::endl;;
    }
}
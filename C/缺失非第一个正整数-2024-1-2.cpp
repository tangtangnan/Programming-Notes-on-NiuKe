#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minNumberDisappeared(vector<int>& nums) 
    {
        int n = nums.size();
        int res = 1;

        unordered_map<int, int> mp;
        //哈希表记录数组中出现的每个数字
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        //从1开始找到哈希表中第一个没有出现的正整数
        while (mp.find(res) != mp.end())
        {
            res++;
        }
        return res;
    }
};

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) 
    {
        unordered_map<int, int> mp;
        vector<int> res;
        //遍历数组
        for (int i = 0; i < array.size(); i++)
            //统计每个数出现的频率
            mp[array[i]]++;
        //再次遍历数组
        for (int i = 0; i < array.size(); i++)
            //找到频率为1的两个数
            if (mp[array[i]] == 1)
                res.push_back(array[i]);
        //整理次序
        if (res[0] < res[1])
            return res;
        else
            return { res[1], res[0] };
    }
};

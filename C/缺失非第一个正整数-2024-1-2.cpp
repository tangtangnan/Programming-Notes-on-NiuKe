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
        //��ϣ���¼�����г��ֵ�ÿ������
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        //��1��ʼ�ҵ���ϣ���е�һ��û�г��ֵ�������
        while (mp.find(res) != mp.end())
        {
            res++;
        }
        return res;
    }
};

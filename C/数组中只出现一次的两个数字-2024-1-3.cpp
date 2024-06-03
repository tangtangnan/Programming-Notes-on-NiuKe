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
        //��������
        for (int i = 0; i < array.size(); i++)
            //ͳ��ÿ�������ֵ�Ƶ��
            mp[array[i]]++;
        //�ٴα�������
        for (int i = 0; i < array.size(); i++)
            //�ҵ�Ƶ��Ϊ1��������
            if (mp[array[i]] == 1)
                res.push_back(array[i]);
        //�������
        if (res[0] < res[1])
            return res;
        else
            return { res[1], res[0] };
    }
};

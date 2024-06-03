#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) 
    {
        // write code here
        unordered_map<int, int> mp;
        int res = 0;

        for (int left = 0, right = 0; right < arr.size(); right++)
        {
            mp[arr[right]]++;
            while (mp[arr[right]] > 1)
            {
                mp[arr[left++]]--;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
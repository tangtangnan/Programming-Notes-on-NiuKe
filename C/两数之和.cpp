#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        // write code here
        int n = numbers.size();
        vector <int> res;

        if (!n)
        {
            return res;
        }

        unordered_map<int, int> hashmap;
        for (int i = 0; i < n; i++)
        {
            if (hashmap.find(target - numbers[i]) != hashmap.end())
            {
                res.push_back(hashmap[target - numbers[i]] + 1);
                res.push_back(i + 1);
            }
            else
            {
                hashmap[numbers[i]] = i;
            }
        }
        return res;
    }
};
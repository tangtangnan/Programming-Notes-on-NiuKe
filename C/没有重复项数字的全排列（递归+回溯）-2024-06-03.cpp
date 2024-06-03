#include<iostream>
#include <algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<set>
using namespace std;


class Solution {
public:
    void recursion(vector<vector<int> >& res, vector<int>& num, int index) 
    {
        //分枝进入结尾，找到一种排列
        if (index == num.size() - 1)
            res.push_back(num);
        else 
        {
            //用于记录已经使用过的元素
            set<int> used;
            //遍历后续的元素
            for (int i = index; i < num.size(); i++) 
            {
                if (used.count(num[i]) > 0) 
                {
                    continue;
                }
                used.insert(num[i]);

                //交换二者
                swap(num[i], num[index]);
                //继续往后找
                recursion(res, num, index + 1);
                //回溯
                swap(num[i], num[index]);
            }
        }
    }

    vector<vector<int> > permute(vector<int>& num)
    {
        //先按字典序排序
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        //递归获取
        recursion(res, num, 0);
        return res;
    }
};

int main()
{
    Solution ss;
    //vector<int> num = {1,1,7};//重复vector需要剔除
    vector<int> num = { 1,1,7 };
    vector<vector<int> > num_t = ss.permute(num);

    for (const auto& row : num_t) 
    {
        for (const auto& num : row) 
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

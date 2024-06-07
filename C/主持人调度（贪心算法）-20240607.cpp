#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution 
{
public:
    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd)
    {
        vector<int> start;
        vector<int> end;
        //分别得到活动起始时间
        for (int i = 0; i < n; i++)
        {
            start.push_back(startEnd[i][0]);
            end.push_back(startEnd[i][1]);
        }
        //分别对开始和结束时间排序
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int res = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            //新开始的节目大于上一轮结束的时间，主持人不变
            if (start[i] >= end[j])
                j++;
            else
                //主持人增加
                res++;
        }
        return res;
    }
};

int main()
{
    Solution ss;
    vector<vector<int> > num = {{-4, -2},{ -3, -1 } };
    int ret = ss.minmumNumberOfHost(2, num);

    std::cout << ret << " " << std::endl;

}

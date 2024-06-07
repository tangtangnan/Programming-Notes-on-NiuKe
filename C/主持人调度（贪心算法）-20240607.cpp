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
        //�ֱ�õ����ʼʱ��
        for (int i = 0; i < n; i++)
        {
            start.push_back(startEnd[i][0]);
            end.push_back(startEnd[i][1]);
        }
        //�ֱ�Կ�ʼ�ͽ���ʱ������
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int res = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            //�¿�ʼ�Ľ�Ŀ������һ�ֽ�����ʱ�䣬�����˲���
            if (start[i] >= end[j])
                j++;
            else
                //����������
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

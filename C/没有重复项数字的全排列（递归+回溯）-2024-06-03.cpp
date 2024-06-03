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
        //��֦�����β���ҵ�һ������
        if (index == num.size() - 1)
            res.push_back(num);
        else 
        {
            //���ڼ�¼�Ѿ�ʹ�ù���Ԫ��
            set<int> used;
            //����������Ԫ��
            for (int i = index; i < num.size(); i++) 
            {
                if (used.count(num[i]) > 0) 
                {
                    continue;
                }
                used.insert(num[i]);

                //��������
                swap(num[i], num[index]);
                //����������
                recursion(res, num, index + 1);
                //����
                swap(num[i], num[index]);
            }
        }
    }

    vector<vector<int> > permute(vector<int>& num)
    {
        //�Ȱ��ֵ�������
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        //�ݹ��ȡ
        recursion(res, num, 0);
        return res;
    }
};

int main()
{
    Solution ss;
    //vector<int> num = {1,1,7};//�ظ�vector��Ҫ�޳�
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

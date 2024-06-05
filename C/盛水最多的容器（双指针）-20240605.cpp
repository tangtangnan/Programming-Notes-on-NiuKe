#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<set>
using namespace std;

//̰���㷨

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        //�ų������γ����������
        if (height.size() < 2)
            return 0;
        int res = 0;
        //˫ָ�����ҽ�
        int left = 0;
        int right = height.size() - 1;
        //��ͬ���������е�����
        while (left < right) 
        {
            //��������ˮ����
            int capacity = min(height[left], height[right]) * (right - left);
            //ά�����ֵ 
            res = max(res, capacity);
            //���������϶̵ı�
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return res;
    }
};

int main()
{
    Solution ss;
    vector<int> num = { 1,7,3,2,4,5,8,2,2,2,7 };
    int num_t = ss.maxArea(num);

    std::cout << num_t << " "<< std::endl;

}

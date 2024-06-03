#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int>& num) 
    {
        vector<vector<int> > res;
        int n = num.size();
        //������Ԫ��
        if (n < 3)
        {
            return res;
        }
        //����
        sort(num.begin(), num.end());
        for (int i = 0; i < n - 2; i++) 
        {
            if (i != 0 && num[i] == num[i - 1])
            {
                continue;
            }

            //��������β˫ָ��
            int left = i + 1;
            int right = n - 1;
            //���õ�ǰ���ĸ�ֵΪĿ��
            int target = -num[i];
            while (left < right) 
            {
                //˫ָ��ָ��Ķ�ֵ���ΪĿ�꣬�������num[i]���0
                if (num[left] + num[right] == target) 
                {
                    res.push_back({ num[i], num[left], num[right] });
                    while (left + 1 < right && num[left] == num[left + 1])
                    {
                        //ȥ��
                        left++;
                    }
                    while (right - 1 > left && num[right] == num[right - 1])
                    {
                        //ȥ��
                        right--;
                    }
                    //˫ָ�����м�����
                    left++;
                    right--;
                }
                //˫ָ��ָ��Ķ�ֵ��Ӵ���Ŀ�꣬��ָ������
                else if (num[left] + num[right] > target)
                {
                    right--;
                }
                //˫ָ��ָ��Ķ�ֵ���С��Ŀ�꣬��ָ������
                else
                {
                    left++;
                }
            }
        }
        return res;
    }
};

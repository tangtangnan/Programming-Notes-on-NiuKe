#include<iostream>
#include<cmath>
//#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        //���ڴ������鳤�ȵ�ʱ�򣬷��ؿ�
        if (size <= num.size() && size != 0)
            //�������Ҫ�ճ����ڴ�С������Խ��
            for (int i = 0; i <= num.size() - size; i++) {
                //Ѱ��ÿ���������ֵ
                int max = 0;
                for (int j = i; j < i + size; j++) {
                    if (num[j] > max)
                        max = num[j];
                }
                res.push_back(max);
            }
        return res;
    }
};

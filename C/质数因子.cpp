#include<iostream>
#include<cmath>
using namespace std;

int main890() {
    long n;
    cin >> n;
    for (long i = 2; i <= sqrt(n) && i <= n; i++) 
    {  //��С����������ӣ������Ӳ��ᳬ�����Ŀ���
        while (n % i == 0) 
        { //���е�����ǰ��ȫ�������������Ͳ����к�����
            cout << i << " ";
            n /= i; //����������
        }
    }
    if (n - 1) //�Լ������������
        cout << n << " ";
    return 0;
}

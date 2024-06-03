#include<iostream>
#include<cmath>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        ListNode* NewHead = NULL;

        while (NULL != pHead)
        {
            ListNode* tmp = pHead->next;

            pHead->next = NewHead;
            NewHead = pHead;
            pHead = tmp;
        }

        return NewHead;
    }
};
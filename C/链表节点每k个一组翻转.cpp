#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

 struct ListNode {
     int val;
     struct ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

 // 递归
 class Solution1 {
 public:
     ListNode* reverseKGroup(ListNode* head, int k)
     {
         //找到每次翻转的尾部
         ListNode* tail = head;
         //遍历k次到尾部
         for (int i = 0; i < k; i++) 
         {
             //如果不足k到了链表尾，直接返回，不翻转
             if (tail == NULL)
             {
                 return head;
             }
             tail = tail->next;
         }
         //翻转时需要的前序和当前节点
         ListNode* pre = NULL;
         ListNode* cur = head;
         //在到达当前段尾节点前
         while (cur != tail) 
         {
             //翻转
             ListNode* temp = cur->next;
             cur->next = pre;
             pre = cur;
             cur = temp;
         }
         //当前尾指向下一段要翻转的链表
         head->next = reverseKGroup(tail, k);
         return pre;
     }
 };

 //stack   重点使用  
 class Solution {
 public:
     ListNode* reverseKGroup(ListNode* head, int k) 
     {
         if (head == NULL)
             return head;

         ListNode* head2 = new ListNode(0);//新建链表 
         ListNode* p = head2;//p是头指针 
         stack<int>s, s2;

         while (head) 
         {//遍历旧链表 
             s.push(head->val);//权值压入栈 
             if (s.size() == k) 
             {//当栈满k个元素，就将栈内元素全部出栈用以新建链表 
                 while (!s.empty()) 
                 {
                     p->next = new ListNode(s.top()); //获取栈顶元素不删除值
                     s.pop();//新建链表  //获取栈顶元素并删除
                     p = p->next;//指针后移 
                 }
             }
             head = head->next;//指针后移 
         }
         while (!s.empty()) 
         {//当栈s还有剩余，即链表结点不能被k整除时，将剩下的元素入两次栈，即可实现原顺序的结点权值  
             s2.push(s.top());
             s.pop();
         }
         while (!s2.empty())
         {
             p->next = new ListNode(s2.top());
             s2.pop();//新建链表 
             p = p->next;//指针后移 
         }
         return head2->next;//返回结果链表 
     }
 };

 int mainwe() 
 {
     ListNode* head = nullptr; // 头节点指针，初始化为空  
     ListNode* current = nullptr; // 当前节点指针，初始化为空  
     ListNode* Rev = NULL;

     for (int i = 0; i < 4; i++) 
     {
         // 创建新节点  
         ListNode* newNode = new ListNode(i);

         // 将当前节点指向新节点  
         if(NULL != current)
         {
             current->next = newNode;
         }

         // 更新当前节点为新节点  
         current = newNode;

         // 如果链表为空，将头节点指向新节点  
         if (head == nullptr)
         {
             head = newNode;
         }
     }

     // 打印链表的值（从头节点开始）  
     ListNode* temp = head;
     while (temp != nullptr) 
     {
         cout << temp->val << " ";
         temp = temp->next;
     }
     cout << endl;


     Solution a;
     Rev = a.reverseKGroup(head, 3);
     while (Rev != nullptr)
     {
         cout << Rev->val << " ";
         Rev = Rev->next;
     }
     cout << endl;

     return 0;
 }
#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

 struct ListNode {
     int val;
     struct ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

 // �ݹ�
 class Solution1 {
 public:
     ListNode* reverseKGroup(ListNode* head, int k)
     {
         //�ҵ�ÿ�η�ת��β��
         ListNode* tail = head;
         //����k�ε�β��
         for (int i = 0; i < k; i++) 
         {
             //�������k��������β��ֱ�ӷ��أ�����ת
             if (tail == NULL)
             {
                 return head;
             }
             tail = tail->next;
         }
         //��תʱ��Ҫ��ǰ��͵�ǰ�ڵ�
         ListNode* pre = NULL;
         ListNode* cur = head;
         //�ڵ��ﵱǰ��β�ڵ�ǰ
         while (cur != tail) 
         {
             //��ת
             ListNode* temp = cur->next;
             cur->next = pre;
             pre = cur;
             cur = temp;
         }
         //��ǰβָ����һ��Ҫ��ת������
         head->next = reverseKGroup(tail, k);
         return pre;
     }
 };

 //stack   �ص�ʹ��  
 class Solution {
 public:
     ListNode* reverseKGroup(ListNode* head, int k) 
     {
         if (head == NULL)
             return head;

         ListNode* head2 = new ListNode(0);//�½����� 
         ListNode* p = head2;//p��ͷָ�� 
         stack<int>s, s2;

         while (head) 
         {//���������� 
             s.push(head->val);//Ȩֵѹ��ջ 
             if (s.size() == k) 
             {//��ջ��k��Ԫ�أ��ͽ�ջ��Ԫ��ȫ����ջ�����½����� 
                 while (!s.empty()) 
                 {
                     p->next = new ListNode(s.top()); //��ȡջ��Ԫ�ز�ɾ��ֵ
                     s.pop();//�½�����  //��ȡջ��Ԫ�ز�ɾ��
                     p = p->next;//ָ����� 
                 }
             }
             head = head->next;//ָ����� 
         }
         while (!s.empty()) 
         {//��ջs����ʣ�࣬�������㲻�ܱ�k����ʱ����ʣ�µ�Ԫ��������ջ������ʵ��ԭ˳��Ľ��Ȩֵ  
             s2.push(s.top());
             s.pop();
         }
         while (!s2.empty())
         {
             p->next = new ListNode(s2.top());
             s2.pop();//�½����� 
             p = p->next;//ָ����� 
         }
         return head2->next;//���ؽ������ 
     }
 };

 int mainwe() 
 {
     ListNode* head = nullptr; // ͷ�ڵ�ָ�룬��ʼ��Ϊ��  
     ListNode* current = nullptr; // ��ǰ�ڵ�ָ�룬��ʼ��Ϊ��  
     ListNode* Rev = NULL;

     for (int i = 0; i < 4; i++) 
     {
         // �����½ڵ�  
         ListNode* newNode = new ListNode(i);

         // ����ǰ�ڵ�ָ���½ڵ�  
         if(NULL != current)
         {
             current->next = newNode;
         }

         // ���µ�ǰ�ڵ�Ϊ�½ڵ�  
         current = newNode;

         // �������Ϊ�գ���ͷ�ڵ�ָ���½ڵ�  
         if (head == nullptr)
         {
             head = newNode;
         }
     }

     // ��ӡ�����ֵ����ͷ�ڵ㿪ʼ��  
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
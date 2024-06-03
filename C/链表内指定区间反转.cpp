
 struct ListNode 
{
     int val;
     struct ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param head ListNode��
     * @param m int����
     * @param n int����
     * @return ListNode��
     */
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        //�Ӹ���ͷ
        ListNode* res = new ListNode(-1);
        res->next = head;
        //ǰ��ڵ�
        ListNode* pre = res;
        //��ǰ�ڵ�
        ListNode* cur = head;
        //�ҵ�m
        for (int i = 1; i < m; i++) {
            pre = cur;
            cur = cur->next;
        }
        //��m��ת��n
        for (int i = m; i < n; i++) {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        //����ȥ����ͷ
        return res->next;
    }
};
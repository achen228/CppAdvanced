//环形链表2
//给定一个链表，返回链表开始入环的第一个节点。如果链表无环，则返回null。
//为了表示给定链表中的环，我们使用整数pos来表示链表尾连接到链表中的位置（索引从0开始）。如果 pos 是 -1，则在该链表中没有环。
//说明：不允许修改给定的链表。

#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
};
 
class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                ListNode* meet = fast;
                while (meet != head)
                {
                    head = head->next;
                    meet = meet->next;
                }
                return head;
            }
        }
        return NULL;
    }
};

int main()
{
    ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    n5->val = 5;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;
    Solution so;
    ListNode* ret = so.detectCycle(n1);
    printf("%d\n", ret->val);
    return 0;
}

//查找链表中倒数第k个结点。
//输入一个链表，输出该链表中倒数第k个结点。

#include <iostream>
struct ListNode
{
    int val;
    struct ListNode *next;
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        ListNode* fast = pListHead;
        ListNode* slow = pListHead;

        while (k--)
        {
            if (fast == NULL)
            {
                return NULL;
            }
            fast = fast->next;
        }

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
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
    n5->next = NULL;
    Solution so;
    ListNode* ret = so.FindKthToTail(n1, 3);
    printf("%d\n", ret->val);
    return 0;
}

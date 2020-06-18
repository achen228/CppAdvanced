//相交链表
//编写一个程序，找到两个单链表相交的起始节点。

#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if (!headA || !headB)
        {
            return NULL;
        }

        ListNode* curA = headA;
        ListNode* curB = headB;

        int lenA = 0, lenB = 0;
        while (curA)
        {
            lenA++;
            curA = curA->next;
        }
        while (curB)
        {
            lenB++;
            curB = curB->next;
        }

        int gap = abs(lenA - lenB);
        ListNode* longlist = headA;
        ListNode* shortlist = headB;
        if (lenA < lenB)
        {
            longlist = headB;
            shortlist = headA;
        }

        while (gap--)
        {
            longlist = longlist->next;
        }

        while (longlist != shortlist)
        {
            longlist = longlist->next;
            shortlist = shortlist->next;
        }

        return longlist;
    }
};

int main()
{
    ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n6 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* n7 = (ListNode*)malloc(sizeof(ListNode));
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    n5->val = 5;
    n6->val = 8;
    n7->val = 9;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    n6->next = n7;
    n7->next = n4;
    Solution so;
    ListNode* ret = so.getIntersectionNode(n1, n6);
    printf("%d\n", ret->val);
    return 0;
}

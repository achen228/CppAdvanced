//反转一个单链表(链表逆置)。
//示例 :
//输入: 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL

#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
};

//指针转向法
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* n1 = NULL;
        ListNode* n2 = head;
        ListNode* n3 = head->next;

        while (n2)
        {
            n2->next = n1;
            n1 = n2;
            n2 = n3;

            if (n3)
            {
                n3 = n3->next;
            }
        }
        return n1;
    }
};

//头插法
class Solution2 {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* newhead = NULL;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;
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
    Solution2 so;
    so.reverseList(n1);
    return 0;
}

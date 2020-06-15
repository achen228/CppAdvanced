//合并两个有序链表
//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//示例：
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4

#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }

        if (l2 == NULL)
        {
            return l1;
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (1l && l2)
        {
            if (l1->val < l2->val)
            {
                if (tail == NULL)
                {
                    head = tail = l1;
                }
                else
                {
                    tail->next = l1;
                    tail = l1;
                }
                l1 = l1->next;
            }
            else
            {
                if (tail == NULL)
                {
                    head = tail = l2;
                }
                else
                {
                    tail->next = l2;
                    tail = l2;
                }
                l2 = l2->next;
            }
        }

        if (l1)
        {
            tail->next = l1;
        }
        else if (l2)
        {
            tail->next = l2;
        }
        return head;
    }
};

class Solution2
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1)
        {
            return l2;
        }

        if (!l2)
        {
            return l1;
        }

        ListNode* head = (ListNode*)malloc(sizeof(ListNode));
        ListNode* tail = head;
        tail->next = NULL;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }

        if (l1)
        {
            tail->next = l1;
        }
        else if (l2)
        {
            tail->next = l2;
        }

        ListNode* list = head->next;
        free(head);
        return list;
    }
};

int main()
{
    ListNode* f1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* f2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* f3 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* s1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* s2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* s3 = (ListNode*)malloc(sizeof(ListNode));
    f1->val = 1;
    f2->val = 2;
    f3->val = 4;
    s1->val = 1;
    s2->val = 3;
    s3->val = 4;
    f1->next = f2;
    f2->next = f3;
    f3->next = NULL;
    s1->next = s2;
    s2->next = s3;
    s3->next = NULL;

    Solution2 so;
    so.mergeTwoLists(f1, s1);
    return 0;
}

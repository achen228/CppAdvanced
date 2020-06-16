//链表分割
//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
//给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。

#include <iostream>
struct ListNode
{
    int val;
    struct ListNode *next;
};

class Partition
{
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        ListNode* small = NULL;
        ListNode* small_last = NULL;
        ListNode* big = NULL;
        ListNode* big_last = NULL;

        while (pHead)
        {
            if (pHead->val < x)
            {
                if (small == NULL)
                {
                    small = small_last = pHead;
                }
                else
                {
                    small_last->next = pHead;
                    small_last = pHead;               
                }
                pHead = pHead->next;
            }
            else
            {
                if (big == NULL)
                {
                    big = big_last = pHead;
                }
                else
                {
                    big_last->next = pHead;
                    big_last = pHead;
                }
                pHead = pHead->next;
            }
        }

        if (small == NULL)
        {
            return big;
        }
        else if (big == NULL)
        {
            return small;
        }
        else
        {
            small_last->next = big;
            big_last->next = NULL; // 这步必须有，否则oj超出内存限制
            return small;
        }
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
    n2->val = 3;
    n3->val = 9;
    n4->val = 4;
    n5->val = 5;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    Partition pa;
    pa.partition(n1, 5);
    return 0;
}

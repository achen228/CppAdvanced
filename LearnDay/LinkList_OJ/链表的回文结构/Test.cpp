//链表的回文结构
//题目描述:
//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//测试样例：
//1->2->2->1
//返回：true

#include <iostream>
struct ListNode
{
    int val;
    struct ListNode *next;
};

class PalindromeList
{
public:
    bool chkPalindrome(ListNode* A)
    {
        //求链表长度
        ListNode* cur = A;
        int length = 0;
        while (cur)
        {
            cur = cur->next;
            length++;
        }

        //求中间节点
        ListNode* middle = A;
        for (int i = 0; i < length / 2; i++)
        {
            middle = middle->next;
        }

        //逆置链表后半部分
        ListNode* rhead = NULL;
        while (middle)
        {
            ListNode* Next = middle->next;
            middle->next = rhead;
            rhead = middle;
            middle = Next;
        }

        //进行比较
        while (rhead)
        {
            if (rhead->val != A->val)
            {
                return false;
            }
            rhead = rhead->next;
            A = A->next;
        }
        return true;
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
    n4->val = 2;
    n5->val = 1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    PalindromeList pa;
    int ret = pa.chkPalindrome(n1);
    printf("%d\n", ret);
    return 0;
}

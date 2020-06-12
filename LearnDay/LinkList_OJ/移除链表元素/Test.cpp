//移除链表元素
//删除链表中等于给定值 val 的所有节点。
//示例 :
//输入: 1->2->6->3->4->5->6, val = 6
//输出 : 1->2->3->4->5

#include <iostream>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode* prev = sentinel;
        ListNode* cur = head;
        ListNode* todelete = nullptr;

        while (cur)
        {
            if (cur->val == val)
            {
                prev->next = cur->next;
                todelete = cur;
            }
            else
            {
                prev = cur;
            }
            cur = cur->next;

            if (todelete)
            {
                delete todelete;
                todelete = nullptr;
            }
        }

        ListNode* ret = sentinel->next;
        delete sentinel;
        return ret;
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
    n5->val = 5;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    Solution so;
    ListNode* ret = so.removeElements(n1, 2);
    while (ret)
    {
        printf("%d ", ret->val);
        ret = ret->next;
    }
    printf("\n");
    return 0;
}

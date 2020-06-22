//对链表进行插入排序

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef struct ListNode Node;

ListNode* insertionSortList(ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* sortHead = (Node*)malloc(sizeof(Node));
    sortHead->next = head;
    head = head->next;
    sortHead->next->next = NULL;

    while (head)
    {
        Node* next = head->next;
        Node* prev = sortHead;
        Node* cur = sortHead->next;

        while (cur)
        {
            if (cur->val > head->val)
            {
                prev->next = head;
                head->next = cur;
                break;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }

            if (cur == NULL)
            {
                prev->next = head;
                head->next = NULL;
            }
        }
        head = next;
    }
    return sortHead->next;
}

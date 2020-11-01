/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = cur->next;
        while(cur)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            if(next)
            {
                next = next->next;
            }
        }
        return prev;
    }
};

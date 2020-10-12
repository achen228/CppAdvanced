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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == nullptr)
            return head;
        ListNode* fast = head;
        while(k - 1)
        {
            fast = fast->next;
            k--;
        }
        while(fast->next)
        {
            head = head->next;
            fast = fast->next;
        }
        return head;
    }
};

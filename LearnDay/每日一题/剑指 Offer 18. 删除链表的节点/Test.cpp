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
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return head;

        ListNode* cur = head;
        ListNode* front = nullptr;
        while(cur)
        {
            if(cur->val == val)
            {
                if(front)
                {
                    front->next = cur->next;
                    break; 
                }
                head = cur->next;
                return head;    
            }
            front = cur;
            cur = cur->next;
        }
        return head;
    }
};

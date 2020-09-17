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
    vector<int> reversePrint(ListNode* head) {
        vector<int> v;
        if(head == nullptr)
        {
            return v;
        }

        while(head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        //逆置vector中的元素
        std::reverse(v.begin(), v.end());

        return v;
    }
};

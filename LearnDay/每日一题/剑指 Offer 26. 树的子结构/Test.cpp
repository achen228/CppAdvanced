/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool IsAHaveB(TreeNode* p1, TreeNode* p2)
    {
        // 如果B没有节点了，则B是A的子结构
        if(!p2)
        {
            return true;
        }
        // 如果A没有节点了，但是B还有，则返回false
        if(!p1)
        {
            return false;
        }
        // 如果A和B的val不相等，则返回false
        if(p1->val != p2->val)
        {
            return false;
        }

        return IsAHaveB(p1->left, p2->left) && IsAHaveB(p1->right, p2->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // 空树不是任意一个树的子结构
        if(!A || !B)
        {
            return false;
        }

        bool ret = false;
        // 如果在A中匹配到了与B中相同的val
        if(A->val == B->val)
        {
            ret = IsAHaveB(A, B);
        }
        // 如果没有匹配到，就向A中的左子树去寻找
        if(!ret)
        {
            ret = isSubStructure(A->left, B);
        }
        // 还没有匹配到，就向A中的右子树去寻找
        if(!ret)
        {
            ret = isSubStructure(A->right, B);
        }
        return ret;
    }
};

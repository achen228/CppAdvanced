//二叉树的最近公共祖先
//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    bool Find(TreeNode* root, TreeNode* x)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root == x)
        {
            return true;
        }
        return Find(root->left, x) || Find(root->right, x);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if(root == p || root == q)
        {
            return root;
        }

        bool pInLeft, pInRight, qInLeft, qInRight;
        pInLeft = Find(root->left, p);
        pInRight = !pInLeft;
        qInLeft = Find(root->left, q);
        qInRight = !qInLeft;

        if ((pInLeft && qInRight) || (qInLeft && pInRight))
        {
            return root;
        }

        if (pInLeft && qInLeft)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if(pInRight && qInRight)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return nullptr;
    }
};

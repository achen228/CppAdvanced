//从前序与中序遍历序列构造二叉树
//根据一棵树的前序遍历与中序遍历构造二叉树。可以假设树中没有重复的元素。
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int inbegin, int inend)
    {
        if (inbegin > inend)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[prei]);
        int rooti = inbegin;
        while (rooti <= inend)
        {
            if (inorder[rooti] == preorder[prei])
            {
                break;
            }
            ++rooti;
        }

        if (inbegin <= rooti - 1)
        {
            root->left = _buildTree(preorder, inorder, ++prei, inbegin, rooti - 1);
        }
        else
        {
            root->left = nullptr;
        }

        if (rooti + 1 <= inend)
        {
            root->right = _buildTree(preorder, inorder, ++prei, rooti + 1, inend);
        }
        else
        {
            root->right = nullptr;
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int prei = 0;
        int inbegin = 0, inend = inorder.size() - 1;
        return _buildTree(preorder, inorder, prei, inbegin, inend);
    }
};

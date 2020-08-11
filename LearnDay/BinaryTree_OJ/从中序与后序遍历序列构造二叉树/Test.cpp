//从中序与后序遍历序列构造二叉树
//根据一棵树的中序遍历与后序遍历构造二叉树。你可以假设树中没有重复的元素。
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& prei, int inbegin, int inend)
    {
        if (inbegin > inend)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[prei]);
        int rooti = inbegin;
        while (rooti <= inend)
        {
            if (inorder[rooti] == postorder[prei])
            {
                break;
            }
            ++rooti;
        }

        if (inbegin <= rooti - 1)
        {
            prei = rooti - 1;
            root->left = _buildTree(inorder, postorder, prei, inbegin, rooti - 1);
        }
        else
        {
            root->left = nullptr;
        }

        if (rooti + 1 <= inend)
        {
            prei = inend;
            root->right = _buildTree(inorder, postorder, prei, rooti + 1, inend);
        }
        else
        {
            root->right = nullptr;
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int prei = postorder.size() - 1;
        int inbegin = 0, inend = postorder.size() - 1;
        return _buildTree(inorder, postorder, prei, inbegin, inend);
    }
};

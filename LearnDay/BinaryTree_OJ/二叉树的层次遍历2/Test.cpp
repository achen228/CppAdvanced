//二叉树的层次遍历2
//给定一个二叉树，返回其节点值自底向上的层次遍历（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        if (root != NULL)
        {
            q.push(root);
        }
        while (!q.empty())
        {
            size_t level_size = q.size();
            vector<int> v;
            for (size_t i = 0; i < level_size; ++i)
            {
                TreeNode* ret = q.front();
                q.pop();
                v.push_back(ret->val);

                if (ret->left)
                {
                    q.push(ret->left);
                }
                if (ret->right)
                {
                    q.push(ret->right);
                }
            }
            vv.push_back(v);
        }
        reverse(vv.begin(), vv.end());
        return vv;
    }
};

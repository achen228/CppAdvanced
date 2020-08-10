//二叉树的层序遍历
//给你一个二叉树，请你返回其按 层序遍历 得到的节点值（即逐层地，从左到右访问所有节点）。
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
    vector<vector<int>> levelOrder(TreeNode* root)
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
        return vv;
    }
};

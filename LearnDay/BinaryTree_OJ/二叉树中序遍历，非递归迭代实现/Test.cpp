//二叉树中序遍历，非递归迭代实现
//给定一个二叉树，返回它的中序遍历。
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* top = st.top();
            st.pop();
            v.push_back(top->val);
            cur = top->right;
        }
        return v;
    }
};

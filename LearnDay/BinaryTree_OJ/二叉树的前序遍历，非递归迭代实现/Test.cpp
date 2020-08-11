//二叉树的前序遍历，非递归迭代实现
//给定一个二叉树，返回它的前序遍历。
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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty())
        {
            while (cur)
            {
                v.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* top = st.top();
            st.pop();
            cur = top->right;
        }
        return v;
    }
};

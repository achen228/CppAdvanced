//二叉树搜索树转换成排序双向链表
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    void _Convert(TreeNode* cur, TreeNode*& prev)
    {
        if (cur == nullptr)
        {
            return;
        }

        _Convert(cur->left, prev);
        cur->left = prev;
        if (prev)
        {
            prev->right = cur;
        }
        prev = cur;
        _Convert(cur->right, prev);
    }

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr)
        {
            return nullptr;
        }

        TreeNode* prev = nullptr;
        _Convert(pRootOfTree, prev);

        TreeNode* head = pRootOfTree;
        while (head && head->left)
        {
            head = head->left;
        }
        return head;
    }
};

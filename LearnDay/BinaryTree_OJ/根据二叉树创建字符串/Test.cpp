//根据二叉树创建字符串
//你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
//空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
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
    string tree2str(TreeNode* t)
    {
        string str;
        if (t == NULL)
        {
            return str;
        }

        str += to_string(t->val);
        if (t->left)
        {
            str += '(';
            str += tree2str(t->left);
            str += ')';
        }
        else if (t->right)
        {
            str += "()";
        }

        if (t->right)
        {
            str += '(';
            str += tree2str(t->right);
            str += ')';
        }
        return str;
    }
};

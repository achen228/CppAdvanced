//平衡二叉树
//给定一个二叉树，判断它是否是高度平衡的二叉树。
//本题中，一棵高度平衡二叉树定义为：
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
int Depth(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_depth = Depth(root->left);
    int right_depth = Depth(root->right);
    return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}

bool isBalanced(struct TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }

    int left_depth = Depth(root->left);
    int right_depth = Depth(root->right);
    return abs(left_depth - right_depth) < 2 && isBalanced(root->left) && isBalanced(root->right);
}

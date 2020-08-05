//二叉树的最大深度
//给定一个二叉树，找出其最大深度。
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//说明:叶子节点是指没有子节点的节点。
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}

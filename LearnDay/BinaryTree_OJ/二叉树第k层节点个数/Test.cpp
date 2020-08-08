//二叉树第k层节点个数
typedef struct BinaryTreeNode
{
    int _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
}BTNode;
int BinaryTreeLevelKSize(BTNode* root, int k)
{
    if (root == NULL)
    {
        return 0;
    }
    if (k == 1)
    {
        return 1;
    }

    return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

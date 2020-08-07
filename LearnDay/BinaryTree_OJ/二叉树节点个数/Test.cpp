typedef struct BinaryTreeNode
{
    int _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
}BTNode;
int BinaryTreeSize(BTNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

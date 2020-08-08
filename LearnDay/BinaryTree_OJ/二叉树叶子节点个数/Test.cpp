//二叉树叶子节点个数
typedef struct BinaryTreeNode
{
    int _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
}BTNode;
int BinaryTreeLeafSize(BTNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->_left == NULL && root->_right == NULL)
    {
        return 1;
    }
    return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

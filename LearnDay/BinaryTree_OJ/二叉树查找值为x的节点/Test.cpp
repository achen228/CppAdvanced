//二叉树查找值为x的节点
typedef struct BinaryTreeNode
{
    int _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
}BTNode;
BTNode* BinaryTreeFind(BTNode* root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->_data == x)
    {
        return root;
    }

    BTNode* ret = BinaryTreeFind(root->_left, x);
    if (ret)
    {
        return ret;
    }

    ret = BinaryTreeFind(root->_right, x);
    if (ret)
    {
        return ret;
    }
    return NULL;
}

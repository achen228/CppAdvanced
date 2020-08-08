//二叉树销毁
typedef struct BinaryTreeNode
{
    int _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
}BTNode;
void BinaryTreeDestory(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }
    BinaryTreeDestory(root->_left);
    BinaryTreeDestory(root->_right);
    free(root);
}

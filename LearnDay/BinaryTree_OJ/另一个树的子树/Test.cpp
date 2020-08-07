//另一个树的子树
//给定两个非空二叉树s和t，检验s中是否包含和t具有相同结构和节点值的子树。s的一个子树包括s的一个节点和这个节点的所有子孙。
//s也可以看做它自身的一棵子树。
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }

    if (p == NULL || q == NULL)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    if (s == NULL)
    {
        return false;
    }

    if (isSameTree(s, t))
    {
        return true;
    }
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

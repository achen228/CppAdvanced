//二叉树的后序遍历
//给定一个二叉树，返回它的后序遍历。
//Note: The returned array must be malloced, assume caller calls free().
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
int TreeSize(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _postorderTraversal(struct TreeNode* root, int* arr, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    _postorderTraversal(root->left, arr, pi);
    _postorderTraversal(root->right, arr, pi);
    arr[(*pi)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = TreeSize(root);
    int* arr = (int*)malloc(sizeof(int) * size);
    *returnSize = size;
    int i = 0;
    _postorderTraversal(root, arr, &i);
    return arr;
}

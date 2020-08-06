//二叉树的中序遍历
//给定一个二叉树，返回它的中序遍历。
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

void _inorderTraversal(struct TreeNode* root, int* arr, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    _inorderTraversal(root->left, arr, pi);
    arr[(*pi)++] = root->val;
    _inorderTraversal(root->right, arr, pi);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = TreeSize(root);
    int* arr = (int*)malloc(sizeof(int) * size);
    *returnSize = size;
    int i = 0;
    _inorderTraversal(root, arr, &i);
    return arr;
}

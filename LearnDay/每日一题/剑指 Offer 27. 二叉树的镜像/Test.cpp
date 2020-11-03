/**
* Definition for a binary tree node.
* struct TreeNode
* {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
**/
class Solution {
  public:
    void SwapNode(TreeNode* node)
    {
      if(!node || (!node->left && !node->right))
        return;
      TreeNode* tmp = node->left;
      node->left = node->right;
      node->right = tmp;
    }

    TreeNode* mirrorTree(TreeNode* root) {
      if(!root || (!root->left && !root->right))
        return root;
      SwapNode(root);
      mirrorTree(root->left);
      mirrorTree(root->right);
      return root;
    }
};

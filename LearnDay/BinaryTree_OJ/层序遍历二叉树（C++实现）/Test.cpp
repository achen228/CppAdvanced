//层序遍历二叉树（C++实现）
#include <iostream>
#include <queue>
using namespace std;
struct BTNode
{
    char _data;
    BTNode* _left;
    BTNode* _right;
};
void BinaryTreeLevelOrder(BTNode* root)
{
    queue<BTNode*> q;
    if (root != NULL)
    {
        q.push(root);
    }
    while (!q.empty())
    {
        BTNode* ret = q.front();
        q.pop();
        cout << ret->_data;
        if (ret->_left)
        {
            q.push(ret->_left);
        }
        if (ret->_right)
        {
            q.push(ret->_right);
        }
    }
}

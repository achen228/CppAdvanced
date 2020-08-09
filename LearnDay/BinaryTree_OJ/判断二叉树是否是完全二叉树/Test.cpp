//判断二叉树是否是完全二叉树
#include <iostream>
#include <queue>
using namespace std;
struct BTNode
{
    char _data;
    BTNode* _left;
    BTNode* _right;
};
int BinaryTreeComplete(BTNode* root)
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
        if (ret == NULL)
        {
            break;
        }
        q.push(ret->_left);
        q.push(ret->_right);
    }

    while (!q.empty())
    {
        if (q.front() != NULL)
        {
            return 0;
        }
        q.pop();
    }
    return 1;
}

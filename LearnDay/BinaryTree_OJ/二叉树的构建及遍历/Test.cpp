//二叉树的构建及遍历
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。例如如下的先序遍历字符串： 
//ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
//输入描述:
//输入包括1行字符串，长度不超过100。
//输出描述:
//可能有多组测试数据，对于每组数据，
//输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。
//每个输出结果占一行。
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
    char _ch;
    struct TreeNode* _left;
    struct TreeNode* _right;
}TreeNode;

TreeNode* ReBuild(char* ch, int* pi)
{
    if (ch[*pi] == '#')
    {
        return NULL;
    }
    else
    {
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        root->_ch = ch[*pi];
        ++(*pi);
        root->_left = ReBuild(ch, pi);
        ++(*pi);
        root->_right = ReBuild(ch, pi);
        return root;
    }
}

void inorderTraversal(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->_left);
    printf("%c ", root->_ch);
    inorderTraversal(root->_right);
}

int main()
{
    char ch[100];
    scanf("%s", ch);
    //构建二叉树
    int i = 0;
    TreeNode* root = ReBuild(ch, &i);
    //中序遍历
    inorderTraversal(root);
    return 0;
}

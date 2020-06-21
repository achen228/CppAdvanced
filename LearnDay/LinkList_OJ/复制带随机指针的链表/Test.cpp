//复制带随机指针的链表
//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的 深拷贝。 
//我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
//val：一个表示 Node.val 的整数。
//random_index：随机指针指向的节点索引（范围从 0 到 n - 1）；如果不指向任何节点，则为  null 。

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* copyRandomList(struct Node* head)
{
    //拷贝节点，插入到原链表中
    Node* cur = head;
    while (cur)
    {
        Node* next = cur->next;

        Node* copyNode = (Node*)malloc(sizeof(Node));
        copyNode->val = cur->val;
        copyNode->random = NULL;
        copyNode->next = NULL;

        cur->next = copyNode;
        copyNode->next = next;

        cur = next;
    }

    //置random
    cur = head;
    while (cur)
    {
        Node* copyNode = cur->next;
        if (cur->random)
        {
            copyNode->random = cur->random->next;
        }
        else
        {
            copyNode->random = NULL;
        }

        cur = cur->next->next;
    }

    //将原链表和复制的新链表拆分
    cur = head;
    Node* copyHead = NULL;
    Node* copyTail = NULL;
    while (cur)
    {
        Node* copyNode = cur->next;
        Node* next = copyNode->next;

        if (copyTail == NULL)
        {
            copyHead = copyTail = copyNode;
        }
        else
        {
            copyTail->next = copyNode;
            copyTail = copyNode;
        }

        cur->next = next; //连接原链表
        cur = next;
    }
    return copyHead;
}

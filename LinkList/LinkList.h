#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node
{
	struct Node* _next;
	DataType _data;
}Node;

//实现不带头单向非循环链表
typedef struct LinkList
{
	Node* _head; //表示链表真正的头节点，即第一个有效数据的位置
}LinkList;

void Init(LinkList* ll)
{
	ll->_head = NULL;
}

Node* CreatNode(DataType data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	return node;
}

//尾插
void PushBack(LinkList* ll, DataType data)
{
	Node* node = CreatNode(data);
	if (ll->_head == NULL)
	{
		ll->_head = node;
	}
	else
	{
		//找到最后一个数据元素
		Node* last = ll->_head;
		while (last->_next)
		{
			last = last->_next;
		}
		last->_next = node;
	}
}

//尾删
void PopBack(LinkList* ll)
{
	if (ll->_head)
	{
		//找到最后一个节点，遍历的过程中，更新prev
		Node* prev = NULL;
		Node* tail = ll->_head;
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}

		if (tail == ll->_head)
		{
			//如果删除的为头节点或者链表中只有一个节点
			ll->_head = NULL;
		}
		else
		{
			prev->_next = NULL;
		}
		free(tail);
	}
}

//头插
void PushFront(LinkList* ll, DataType data)
{
	Node* node = CreatNode(data);
	if (ll->_head == NULL)
	{
		ll->_head = node;
	}
	else
	{
		node->_next = ll->_head;
		ll->_head = node;
	}
}

//头删
void PopFront(LinkList* ll)
{
	if (ll->_head)
	{
		Node* cur = ll->_head;
		ll->_head = cur->_next;
		free(cur);
	}
}

//头删
void PopFront2(Node** head)
{
	if (*head)
	{
		Node* cur = (*head)->_next;
		free(*head);
		*head = cur;
	}
}

//在位置pos后插入数据元素
void InsertAfter(Node* pos, DataType data)
{
	if (pos == NULL)
	{
		return;
	}

	Node* node = CreatNode(data);
	node->_next = pos->_next;
	pos->_next = node;
}

//删除位置pos后的数据元素
void EraseAfter(Node* pos)
{
	if (pos == NULL)
	{
		return;
	}

	Node* next = pos->_next;
	if (next)
	{
		pos->_next = next->_next;
		free(next);
	}
}

//查找
Node* Find(LinkList* ll, DataType data)
{
	Node* cur = ll->_head;
	while (cur)
	{
		if (cur->_data == data)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void Print(LinkList* ll)
{
	Node* cur = ll->_head;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

//销毁链表
void Destroy(LinkList* ll)
{
	Node* cur = ll->_head;
	while (cur)
	{
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
}

//查找链表中倒数第二个节点
Node* FindLastPrev(LinkList* ll)
{
	if (ll->_head == NULL)
	{
		return NULL;
	}

	Node* cur = ll->_head;
	while (cur->_next->_next != NULL)
	{
		cur = cur->_next;
	}
	return cur;
}

//删除链表中第一个遇到的data所在的节点
void Remove(LinkList* ll, DataType data)
{
	if (ll->_head == NULL)
	{
		return;
	}

	Node* cur = ll->_head;
	if (cur->_data == data)
	{
		ll->_head = cur->_next;
		free(cur);
		return;
	}

	while (cur->_next != NULL)
	{
		if (cur->_next->_data == data)
		{
			Node* next = cur->_next;
			cur->_next = next->_next;
			free(next);
			return;
		}
		cur = cur->_next;
	}
}

#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

//带头双向循环链表实现
typedef struct Node
{
	DataType _data;
	struct Node* _next;
	struct Node* _prev;
}Node;

typedef struct List
{
	Node* _head;
}List;

Node* CreatNode(DataType data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->_prev = node->_next = NULL;
	node->_data = data;
	return node;
}

void Init(List* ls)
{
	//创建一个头节点，构成循环结构
	ls->_head = CreatNode(0);
	ls->_head->_next = ls->_head;
	ls->_head->_prev = ls->_head;
}

void PushBack(List* ls, DataType data)
{
	Node* node = CreatNode(data);
	Node* last = ls->_head->_prev;

	last->_next = node;
	node->_prev = last;

	node->_next = ls->_head;
	ls->_head->_prev = node;
}

void PopBack(List* ls)
{
	if (ls->_head->_next == ls->_head)
	{
		return;
	}

	Node* last = ls->_head->_prev;
	Node* prev = last->_prev;

	prev->_next = ls->_head;
	ls->_head->_prev = prev;
	free(last);
}

void PushFront(List* ls, DataType data)
{
	Node* front = ls->_head->_next;
	Node* node = CreatNode(data);

	node->_next = front;
	front->_prev = node;

	node->_prev = ls->_head;
	ls->_head->_next = node;
}

void PopFront(List* ls)
{
	if (ls->_head->_next == ls->_head)
	{
		return;
	}

	Node* front = ls->_head->_next;
	Node* next = front->_next;

	free(front);
	ls->_head->_next = next;
	next->_prev = ls->_head;
}

//在pos位置前插入数据元素
void Insert(Node* pos, DataType data)
{
	Node* prev = pos->_prev;
	Node* node = CreatNode(data);
	prev->_next = node;
	node->_prev = prev;

	node->_next = pos;
	pos->_prev = node;
}

//删除pos所在位置的数据元素
void Erase(Node* pos)
{
	if (pos->_next == pos)
	{
		return;
	}

	Node* prev = pos->_prev;
	Node* next = pos->_next;
	free(pos);
	prev->_next = next;
	next->_prev = prev;
}

void Destroy(List* ls)
{
	Node* cur = ls->_head->_next;
	while (cur != ls->_head)
	{
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(ls->_head);
	ls->_head = NULL;
}

void Print(List* ls)
{
	Node* cur = ls->_head->_next;
	while (cur != ls->_head)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node
{
	struct Node* _next;
	DataType _data;
}Node;

typedef struct Queue
{
	Node* _front;
	Node* _rear;
	size_t _size;
}Queue;

void Init(Queue* q)
{
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

Node* CreatNode(DataType data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	return node;
}

void Push(Queue* q, DataType data)
{
	Node* node = CreatNode(data);
	if (q->_front == NULL)
	{
		q->_front = q->_rear = node;
	}
	else
	{
		q->_rear->_next = node;
		q->_rear = node;
	}
	++q->_size;
}

void Pop(Queue* q)
{
	if (q->_front)
	{
		Node* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		if (q->_front == NULL)
		{
			q->_rear = NULL;
		}
		--q->_size;
	}
}

DataType Front(Queue* q)
{
	return q->_front->_data;
}

DataType Back(Queue* q)
{
	return q->_rear->_data;
}

size_t Size(Queue* q)
{
	return q->_size;
}

int Empty(Queue* q)
{
	if (q->_front == NULL)
	{
		return 1;
	}
	return 0;
}

void Destroy(Queue* q)
{
	Node* cur = q->_front;
	while (cur)
	{
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

void Print(Queue* q)
{
	Node* cur = q->_front;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

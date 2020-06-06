#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct MyCircularQueue
{
	int* _arr;
	int _capacity;
	int _front;
	int _rear;
}MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->_arr = (int*)malloc(sizeof(int) * (k + 1));
	cq->_capacity = k + 1;
	cq->_front = 0;
	cq->_rear = 0;
	return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}

	obj->_arr[obj->_rear] = value;
	obj->_rear = (obj->_rear + 1) % obj->_capacity;
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}

	obj->_front = (obj->_front + 1) % obj->_capacity;
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}

	return obj->_arr[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}

	return obj->_arr[(obj->_rear - 1 + obj->_capacity) % obj->_capacity];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->_front == obj->_rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->_rear + 1) % obj->_capacity == obj->_front;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	obj->_front = obj->_rear = 0;
	free(obj);
}

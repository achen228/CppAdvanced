#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef int DataType;

//堆的定义
typedef struct Heap
{
	DataType* _arr;
	size_t _size;
	size_t _capacity;
}Heap;

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//向下调整
void AdJustDown(DataType* arr, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			++child;
		}

		if (arr[parent] > arr[child])
		{
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//向上调整
void AdJustUp(DataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[parent] > arr[child])
		{
			Swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//初始化
void Init(Heap* hp)
{
	hp->_arr = NULL;
	hp->_size = hp->_capacity = 0;
}

//创建小堆
void CreatHeap(Heap* hp, DataType* arr, int n)
{
	hp->_arr = (DataType*)malloc(sizeof(DataType) * n);
	memcpy(hp->_arr, arr, sizeof(DataType) * n);
	hp->_size = hp->_capacity = n;

	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdJustDown(hp->_arr, n, i);
	}
}

//插入元素
void Push(Heap* hp, DataType val)
{
	//扩容
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_arr = realloc(hp->_arr, sizeof(DataType) * hp->_capacity);
	}

	hp->_arr[hp->_size++] = val;
	AdJustUp(hp->_arr, hp->_size - 1);
}

//删除堆顶元素
void Pop(Heap* hp)
{
	assert(hp->_size != 0);
	Swap(&hp->_arr[0], &hp->_arr[hp->_size - 1]);
	--hp->_size;
	AdJustDown(hp->_arr, hp->_size, 0);
}

//返回堆顶元素
DataType Top(Heap* hp)
{
	assert(hp->_size != 0);
	return hp->_arr[0];
}

//判断堆是否为空
bool Empty(Heap* hp)
{
	return hp->_size == 0 ? true : false;
}

//销毁
void Destroy(Heap* hp)
{
	if (hp->_arr)
	{
		free(hp->_arr);
		hp->_arr = NULL;
		hp->_size = hp->_capacity = 0;
	}
}

//打印堆
void Print(Heap* hp)
{
	for (size_t i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_arr[i]);
	}
	printf("\n");
}

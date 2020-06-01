#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType; //数据类型

//动态顺序表
typedef struct SeqList
{
	DataType* _array;
	size_t _size; //有效元素个数
	size_t _capacity; //容量
}SeqList;

//初始化
void Init(SeqList* sl)
{
	sl->_array = (DataType*)malloc(4 * sizeof(DataType));
	sl->_capacity = 4;
	sl->_size = 0;
}

//检查容量
void CheckCapacity(SeqList* sl)
{
	//增容
	if (sl->_capacity == sl->_size)
	{
		sl->_capacity *= 2;
		sl->_array = (DataType*)realloc(sl->_array, sl->_capacity * sizeof(DataType));
	}
}

//尾插
void PushBack(SeqList* sl, DataType value)
{
	CheckCapacity(sl);
	sl->_array[sl->_size++] = value;
}

//尾删
void PopBack(SeqList* sl)
{
	if (sl->_size)
	{
		--sl->_size;
	}
}

//头插
void PushFront(SeqList* sl, DataType value)
{
	CheckCapacity(sl);
	size_t end = sl->_size;
	while (end > 0)
	{
		sl->_array[end] = sl->_array[end - 1];
		--end;
	}
	sl->_array[0] = value;
	++sl->_size;
}

//头删
void PopFront(SeqList* sl)
{
	if (sl->_size)
	{
		size_t start = 1;
		while (start < sl->_size)
		{
			sl->_array[start - 1] = sl->_array[start];
			++start;
		}
		sl->_size--;
	}
}

//在pos位置前面插入一个数据value
void Insert(SeqList* sl, size_t pos, DataType value)
{
	//判断位置是否合法
	if (pos <= sl->_size)
	{
		CheckCapacity(sl);
		size_t end = sl->_size;
		while (end > pos)
		{
			sl->_array[end] = sl->_array[end - 1];
			--end;
		}
		sl->_array[pos] = value;
		++sl->_size;
	}
}

//删除pos所在位置的数据
void Erase(SeqList* sl, size_t pos)
{
	if (pos < sl->_size)
	{
		size_t start = pos + 1;
		while (start < sl->_size)
		{
			sl->_array[start - 1] = sl->_array[start];
			++start;
		}
		--sl->_size;
	}
}

//查找
int Find(SeqList* sl, DataType value)
{
	for (size_t i = 0; i < sl->_size; i++)
	{
		if (sl->_array[i] == value)
		{
			return i;
		}
	}
	return -1;
}

//打印链表数据
void Print(SeqList* sl)
{
	for (size_t i = 0; i < sl->_size; i++)
	{
		printf("%d ", sl->_array[i]);
	}
	printf("\n");
}

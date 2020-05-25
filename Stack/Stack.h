#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

//顺序表实现栈
typedef struct Stack
{
	DataType* _array;
	size_t _size;
	size_t _capacity;
}Stack;

void Init(Stack* st, size_t n)
{
	st->_array = (DataType*)malloc(n * sizeof(DataType));
	st->_capacity = n;
	st->_size = 0;
}

void Push(Stack* st, DataType data)
{
	//检查容量
	if (st->_size == st->_capacity)
	{
		st->_capacity *= 2;
		st->_array = (DataType*)realloc(st->_array, st->_capacity * sizeof(DataType));
	}

	st->_array[st->_size++] = data;
}

void Pop(Stack* st)
{
	if (st->_size)
	{
		--st->_size;
	}
}

DataType Top(Stack* st)
{
	return st->_array[st->_size - 1];
}

size_t Size(Stack* st)
{
	return st->_size;
}

int Empty(Stack* st)
{
	if (st->_size == 0)
	{
		return 1;
	}
	return 0;
}

void Destroy(Stack* st)
{
	free(st->_array);
	st->_array = NULL;
	st->_size = st->_capacity = 0;
}

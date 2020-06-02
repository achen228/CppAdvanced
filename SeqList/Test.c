#include "SeqList.h"

void Test()
{
	SeqList sl;
	Init(&sl);
	PushBack(&sl, 1);
	PushBack(&sl, 2);
	PushBack(&sl, 3);
	Print(&sl);

	PopBack(&sl);
	Print(&sl);
	PopBack(&sl);
	Print(&sl);
	PopBack(&sl);
	Print(&sl);
}

void Test2()
{
	SeqList sl;
	Init(&sl);
	PushBack(&sl, 3);
	PushBack(&sl, 2);
	PushBack(&sl, 1);
	for (int i = 0; i < 1000; i++)
	{
		PushFront(&sl, i);
	}
	Print(&sl);
}

void Test3()
{
	SeqList sl;
	Init(&sl);
	PushBack(&sl, 3);
	PushFront(&sl, 2);
	PushFront(&sl, 1);
	PushBack(&sl, 4);
	PushBack(&sl, 5);
	PushBack(&sl, 7);
	PushBack(&sl, 9);
	PushBack(&sl, 10);
	Insert(&sl, 5, 6);
	Insert(&sl, 7, 8);
	Insert(&sl, 10, 200);
	Print(&sl);

	PopFront(&sl);
	Print(&sl);
	PopBack(&sl);
	Print(&sl);

	Erase(&sl, 3);
	Print(&sl);
	Erase(&sl, 3);
	Print(&sl);
}

void Test4()
{
	SeqList sl;
	Init(&sl);
	PushBack(&sl, 1);
	PushBack(&sl, 2);
	PushBack(&sl, 3);
	Print(&sl);

	int ret = Find(&sl, 2);
	printf("数据2的位置是:%d\n", ret);
}

int main()
{
	Test4();
	return 0;
}

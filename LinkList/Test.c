#include "LinkList.h"

void Test()
{
	LinkList ll;
	Init(&ll);
	PushBack(&ll, 1);
	PushFront(&ll, 2);
	PushFront(&ll, 3);
	PushFront(&ll, 4);
	PushFront(&ll, 5);
	PushFront(&ll, 6);
	PushBack(&ll, 2);
	PushBack(&ll, 3);
	PushBack(&ll, 4);
	PushBack(&ll, 5);
	PushBack(&ll, 6);
	PushBack(&ll, 7);
	//654321234567
	Print(&ll);

	PopFront(&ll);
	Print(&ll);
	PopFront(&ll);
	Print(&ll);
	PopFront(&ll);
	Print(&ll);
	PopFront(&ll);
	Print(&ll);
	PopFront(&ll);
	Print(&ll);
	PopFront(&ll);
	Print(&ll);
	PopFront(&ll);
	Print(&ll);

	PushBack(&ll, 1);
	PushFront(&ll, 2);
	PushFront(&ll, 3);
	PushFront(&ll, 4);
	PushFront(&ll, 5);
	PushFront(&ll, 6);
	PushBack(&ll, 2);
	PushBack(&ll, 3);
	PushBack(&ll, 4);
	PushBack(&ll, 5);
	PushBack(&ll, 6);
	PushBack(&ll, 7);
	//65432345671234567
	Print(&ll);
}

void Test2()
{
	LinkList ll;
	Init(&ll);
	PushBack(&ll, 1);
	PushBack(&ll, 2);
	PushBack(&ll, 3);
	PushBack(&ll, 4);
	PushBack(&ll, 5);
	PushBack(&ll, 6);
	PushBack(&ll, 7);
	//1234567
	Print(&ll);

	PopBack(&ll);
	Print(&ll);
	PopBack(&ll);
	Print(&ll);
	PopBack(&ll);
	Print(&ll);
	PopBack(&ll);
	Print(&ll);
	PopBack(&ll);
	Print(&ll);
	PopBack(&ll);
	Print(&ll);
	PopBack(&ll);
	Print(&ll);
}

void Test3()
{
	LinkList ll;
	Init(&ll);
	PushBack(&ll, 1);
	PushBack(&ll, 2);
	PushBack(&ll, 3);
	PushBack(&ll, 4);
	PushBack(&ll, 5);
	PushBack(&ll, 6);
	PushBack(&ll, 7);
	//1234567
	Print(&ll);

	PopFront2(&ll._head);
	Print(&ll);
	PopFront2(&ll._head);
	Print(&ll);
}

void Test4()
{
	LinkList ll;
	Init(&ll);
	PushBack(&ll, 1);
	PushBack(&ll, 2);
	PushBack(&ll, 3);
	PushBack(&ll, 4);
	PushBack(&ll, 5);
	PushBack(&ll, 6);
	PushBack(&ll, 7);
	//1234567
	Print(&ll);

	Node* pos = Find(&ll, 5);
	InsertAfter(pos, 100);
	Print(&ll);
}

void Test5()
{
	LinkList ll;
	Init(&ll);
	PushBack(&ll, 1);
	PushBack(&ll, 2);
	PushBack(&ll, 3);
	PushBack(&ll, 4);
	PushBack(&ll, 5);
	PushBack(&ll, 6);
	PushBack(&ll, 7);
	//1234567
	Print(&ll);

	Node* pos = FindLastPrev(&ll);
	InsertAfter(pos, 600);
	Print(&ll);

	PushBack(&ll, 6);
	Print(&ll);
	Remove(&ll, 6);
	Print(&ll);
}

int main()
{
	Test5();
	return 0;
}

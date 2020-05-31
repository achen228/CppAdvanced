#include "List.h"

void Test()
{
	List ls;
	Init(&ls);
	Print(&ls);

	PushBack(&ls, 1);
	Print(&ls);
	PushBack(&ls, 2);
	Print(&ls);
	PushBack(&ls, 3);
	Print(&ls);
	PushBack(&ls, 4);
	Print(&ls);

	PopBack(&ls);
	Print(&ls);
	PopBack(&ls);
	Print(&ls);
	PopBack(&ls);
	Print(&ls);
	PopBack(&ls);
	Print(&ls);
	PopBack(&ls);
	Print(&ls);
}

void Test2()
{
	List ls;
	Init(&ls);
	PushFront(&ls, 1);
	Print(&ls);
	PushFront(&ls, 2);
	Print(&ls);
	PushFront(&ls, 3);
	Print(&ls);
	PushFront(&ls, 4);
	Print(&ls);

	PopFront(&ls);
	Print(&ls);
	PopFront(&ls);
	Print(&ls);
	PopFront(&ls);
	Print(&ls);
	PopFront(&ls);
	Print(&ls);
	PopFront(&ls);
	Print(&ls);
}

int main()
{
	Test2();
	return 0;
}

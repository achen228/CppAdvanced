#include "Queue.h"

void Test()
{
	Queue q;
	Init(&q);
	Push(&q, 1);
	Push(&q, 2);
	Push(&q, 3);
	Push(&q, 4);
	Print(&q);

	Pop(&q);
	Pop(&q);
	Pop(&q);
	Pop(&q);
	Print(&q);

	Push(&q, 1);
	Push(&q, 2);
	Push(&q, 3);
	Push(&q, 4);
	Print(&q);
}

void Test2()
{
	Queue q;
	Init(&q);
	Push(&q, 1);
	Push(&q, 2);
	Push(&q, 3);
	Push(&q, 4);
	Print(&q);

	while (!Empty(&q))
	{
		printf("%d ", Front(&q));
		Pop(&q);
	}
	printf("\n");
}

int main()
{
	Test2();
	return 0;
}

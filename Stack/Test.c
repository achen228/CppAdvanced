#include "Stack.h"

void Test()
{
	Stack st;
	Init(&st, 2);
	Push(&st, 1);
	Push(&st, 2);
	Push(&st, 3);
	Push(&st, 4);
	Push(&st, 5);

	while (!Empty(&st))
	{
		printf("%d ", Top(&st));
		Pop(&st);
	}
	printf("\n");

	Destroy(&st);
}

int main()
{
	Test();
	return 0;
}

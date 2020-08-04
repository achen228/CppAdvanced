#include "Heap.h"

void Test1()
{
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Heap hp;
	Init(&hp);
	CreatHeap(&hp, arr, n);
	Print(&hp);

	Push(&hp, 10);
	Print(&hp);

	Pop(&hp);
	Print(&hp);

	Destroy(&hp);
}

void Test2()
{
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Heap hp;
	Init(&hp);
	CreatHeap(&hp, arr, n);
	Print(&hp);

	//依次去打印堆顶元素，结果为升序
	while (!Empty(&hp))
	{
		printf("%d ", Top(&hp));
		Pop(&hp);
	}
	printf("\n");

	Destroy(&hp);
}

void TestTopK()
{
	int n = 10000;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 1000000;
	}
	int k = 5;
	arr[53] = 1000000 + 1;
	arr[530] = 1000000 + 2;
	arr[2000] = 1000000 + 3;
	arr[6999] = 1000000 + 4;
	arr[8888] = 1000000 + 5;

	Heap hp;
	Init(&hp);
	CreatHeap(&hp, arr, k);
	for (int i = k; i < n; ++i)
	{
		if (Top(&hp) < arr[i])
		{
			Pop(&hp);
			Push(&hp, arr[i]);
		}
	}
	Print(&hp);
}

int main()
{
	TestTopK();
	return 0;
}

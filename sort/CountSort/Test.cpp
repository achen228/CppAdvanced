#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Print(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//计数排序
//时间复杂度 O(Max(range, n))
//空间复杂度 O(range)
void CountSort(int* arr, int n)
{
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}

		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	int range = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int) * range);
	memset(countArr, 0, sizeof(int) * range);

	//统计次数
	for (int i = 0; i < n; ++i)
	{
		countArr[arr[i] - min]++;
	}
	//根据次数进行排序
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
		{
			arr[j++] = i + min;
		}
	}
}

int main()
{
	int arr[] = { 9, 6, 2, 5, 7 ,4, 8, 6, 3, 1 };
	int length = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, length);
	Print(arr, length);
	return 0;
}

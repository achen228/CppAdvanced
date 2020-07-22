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

//归并排序
//时间复杂度 O(N*logN), 最坏 O(N*logN) 最好 O(N*logN)
//空间复杂度 O(N)
//稳定
void InMergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}

	int middle = (begin + end) >> 1;
	//拆分 [begin, middle] [middle + 1, end] 无序
	InMergeSort(arr, begin, middle, tmp);
	InMergeSort(arr, middle + 1, end, tmp);

	//合并 [begin, middle] [middle + 1, end] 有序 
	int begin1 = begin, end1 = middle;
	int begin2 = middle + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}

	if (begin1 <= end1)
	{
		while (begin1 <= end1)
		{
			tmp[index++] = arr[begin1++];
		}		
	}
	else
	{
		while (begin2 <= end2)
		{
			tmp[index++] = arr[begin2++];
		}
	}

	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	InMergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

int main()
{
	int arr[] = { 9, 6, 2, 5, 7 ,4, 8, 6, 3, 1 };
	int length = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, length);
	Print(arr, length);
	return 0;
}

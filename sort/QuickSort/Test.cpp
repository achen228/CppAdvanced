#include <stdio.h>

void Print(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//快速排序
//时间复杂度 O(N*logN), 最坏 O(N^2) 最好 O(N*logN)
//空间复杂度 O(logN)
//不稳定

int GetMiddleKey(int* arr, int begin, int end)
{
	int middle = (begin + end) >> 1;
	if (arr[begin] > arr[middle])
	{
		if (arr[end] < arr[middle])
		{
			return middle;
		}
		else if (arr[begin] > arr[end]) //arr[end] > arr[middle]
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
	else //arr[begin] < arr[middle]
	{
		if (arr[end] > arr[middle])
		{
			return middle;
		}
		else if (arr[begin] > arr[end]) //arr[end] < arr[middle]
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
}

//Hoare法(左右指针法)
int Hoare(int* arr, int begin, int end)
{
	int middle_key = GetMiddleKey(arr, begin, end);
	Swap(&arr[middle_key], &arr[end]);

	int key = arr[end];
	int keyval = end;
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
		{
			begin++;
		}

		while (begin < end && arr[end] >= key)
		{
			end--;
		}
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[begin], &arr[keyval]);
	return begin;
}

//挖坑法
int DigPitMethod(int* arr, int begin, int end)
{
	int middle_key = GetMiddleKey(arr, begin, end);
	Swap(&arr[middle_key], &arr[end]);

	int key = arr[end];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
		{
			begin++;
		}
		arr[end] = arr[begin];

		while (begin < end && arr[end] >= key)
		{
			end--;
		}
		arr[begin] = arr[end];
	}
	arr[begin] = key;
	return begin;
}

//前后指针法
int PrevCurMethod(int* arr, int begin, int end)
{
	int middle_key = GetMiddleKey(arr, begin, end);
	Swap(&arr[middle_key], &arr[end]);

	int key = arr[end];
	int cur = begin;
	int prev = begin - 1;
	while (cur < end)
	{
		if (arr[cur] < key && prev++ != cur)
		{
			Swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}
	prev++;
	Swap(&arr[prev], &arr[end]);
	return prev;
}

void InQuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int key = PrevCurMethod(arr, begin, end);
	InQuickSort(arr, begin, key - 1);
	InQuickSort(arr, key + 1, end);
}

void QuickSort(int* arr, int n)
{
	int begin = 0;
	int end = n - 1;
	InQuickSort(arr, begin, end);
}

int main()
{
	int arr[] = { 9, 6, 2, 5, 7 ,4, 8, 6, 3, 1 };
	int length = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, length);
	Print(arr, length);
	return 0;
}

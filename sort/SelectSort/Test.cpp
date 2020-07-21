#include <stdio.h>

void Print(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//直接选择排序
//时间复杂度 O(N^2), 最坏 O(N^2) 最好 O(N^2)
//空间复杂度 O(1)
//不稳定
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void SelectSort(int* arr, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		//找到最大元素和最小元素的数组下标
		int mini = begin, maxi = end;
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}

			if (arr[i] < arr[mini])
			{
				mini = i;
			}
		}

		Swap(&arr[begin], &arr[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&arr[end], &arr[maxi]);
		begin++;
		end--;
	}
}

int main()
{
	int arr[] = { 9, 6, 2, 5, 7 ,4, 8, 6, 3, 1 };
	int length = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, length);
	Print(arr, length);
	return 0;
}

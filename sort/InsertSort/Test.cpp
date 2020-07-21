#include <stdio.h>

void Print(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//直接插入排序
//时间复杂度 O(N^2), 最坏 O(N^2) 最好 O(N)
//空间复杂度 O(1)
//稳定
void InsertSort(int* arr, int n)
{
	//控制end从0到n-2, 每次为单趟排序
	for (int i = 0; i < n - 1; i++)
	{
		//有序区间[0, end]
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

int main()
{
	int arr[] = { 9, 6, 2, 5, 7 ,4, 8, 6, 3, 1 };
	int length = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, length);
	Print(arr, length);
	return 0;
}

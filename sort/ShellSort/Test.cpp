#include <stdio.h>

void Print(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//希尔排序：直接插入排序的改进优化
//时间复杂度 O(N^1.3--N^2), 最坏 O(N^2) 最好 O(N)
//空间复杂度 O(1)
//不稳定
void ShellSort(int* arr, int n)
{
	//gap != 1时：预排序
	//gap == 1时：直接插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //+1保证最后一次gap为1
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

int main()
{
	int arr[] = { 9, 6, 2, 5, 7 ,4, 8, 6, 3, 1 };
	int length = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, length);
	Print(arr, length);
	return 0;
}

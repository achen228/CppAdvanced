//设a[0:n - 1]是已排好序的数组。试改写二分搜索算法，使得当搜索元素x不在数组中时，
//返回小于x的最大元素位置i和大于x的最小元素位置j。当搜索元素在数组中时，i和j相同，
//均为x在数组中的位置。

//代码：
void BinarySearch(int* array, int left, int right, int x, int* max, int* min)
{
	int flag = 0;
	int l = left;
	int r = right;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (array[m] == x)
		{
			flag = 1;
			*max = m;
			*min = m;
		}
		else if (array[m] > x)
			r = m - 1;
		else
			l = m + 1;
	}

	if (!flag)
	{
		*max = l;
		*min = r;
	}
}

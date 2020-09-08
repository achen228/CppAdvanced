//设子数组a[0:k]和a[k + 1:n - 1]已排好序（0 <= k <= n - 1）.
//试设计一个合并这两个子数组为排好序的数组a[0:n - 1]的算法。
//要求算法在最坏情况下所用的计算时间为O（n），且只用到O(1)的辅助空间。
//代码 :
// 假设题目描述默认为 "升序"
// aletf的范围：0 ~ k;
// aright的范围：k + 1 ~ n - 1
          

// 闭区间
void Swap(int* array, int begin, int end)
{
	while (begin <= end)
	{
		int temp = array[begin];
		array[begin] = array[end];
		array[end] = temp;

		begin++;
		end--;
	}
}

// 假设题目描述默认为 "升序"
// aletf的范围：0 ~ k;
// aright的范围：k + 1 ~ n - 1
// 原地归并排序
void MergeFunction(int* array, int lbegin, int lend, int rbegin, int rend)
{
	int i = lbegin;
	int j = rbegin;
	int index = rbegin;

	while (i <= rend && j <= rend)				// i 下标之前的元素全部是已经排好序的
	{
		int leftvalue = array[i];
		int rightvalue = array[j];
		while (leftvalue <= rightvalue && i <= rend)
		{
			i++;
			leftvalue = array[i];
		}

		while (leftvalue > rightvalue&& j <= rend)
		{
			j++;
			rightvalue = array[j];
		}

		// 交换位置 [i, index - 1] [index, j - 1];
		Swap(array, i, j - 1);
		Swap(array, i, (j - 1 - index) + i);
		Swap(array, (j - 1 - index) + i + 1, j - 1);

		i += (j - 1 - index + 1);
		index = j;
	}
}

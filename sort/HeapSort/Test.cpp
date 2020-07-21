void Swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void AdJustDown(int* arr, int n, int root)
{
    int parent = root;
    int child = parent * 2 + 1;
    while (child < n)
    {
        if (child + 1 < n && arr[child] < arr[child + 1])
        {
            ++child;
        }

        if (arr[parent] < arr[child])
        {
            Swap(&arr[child], &arr[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int* arr, int n)
{
    //排升序，建大堆
    for (int i = (n - 1 - 1) / 2; i >= 0; --i)
    {
        AdJustDown(arr, n, i);
    }

    int end = n - 1;
    while (end > 0)
    {
        //把堆顶当前最大的数依次换到最后
        Swap(&arr[0], &arr[end]);
        AdJustDown(arr, end, 0);
        --end;
    }
}

void Test()
{
    int arr[] = { 4, 3, 15, 45, 31, 14, 9, 5, 47, 1 };
    int length = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    Test();
    return 0;
}

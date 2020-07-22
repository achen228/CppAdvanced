#include <iostream>
#include <stack>
using namespace std;

//三数取中
int GetMiddleKey(int* arr, int begin, int end)
{
    int middle = (begin + end) / 2;
    if (arr[begin] > arr[middle])
    {
        if (arr[middle] > arr[end])
        {
            return middle;
        }
        else if (arr[begin] > arr[end]) //arr[middle] < arr[end]
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
            return begin;
        }
        else
        {
            return end;
        }
    }
}

//Hoare（左右指针）版本
int Hoare(int* arr, int begin, int end)
{
    int key_middle = GetMiddleKey(arr, begin, end);
    swap(arr[key_middle], arr[end]);

    int key = arr[end];
    int keyi = end;
    while (begin < end)
    {
        while (begin < end && arr[begin] <= key)
        {
            ++begin;
        }

        while (begin < end && arr[end] >= key)
        {
            --end;
        }
        swap(arr[begin], arr[end]);
    }
    swap(arr[begin], arr[keyi]);
    return begin;
}

//挖坑版本
int DigPitMethod(int* arr, int begin, int end)
{
    int key_middle = GetMiddleKey(arr, begin, end);
    swap(arr[key_middle], arr[end]);

    int key = arr[end];
    while (begin < end)
    {
        while (begin < end && arr[begin] <= key)
        {
            ++begin;
        }
        arr[end] = arr[begin];

        while (begin < end && arr[end] >= key)
        {
            --end;
        }
        arr[begin] = arr[end];
    }
    arr[begin] = key;
    return begin;
}

//前后指针版本
int PrevCurMethod(int* arr, int begin, int end)
{
    int key_middle = GetMiddleKey(arr, begin, end);
    swap(arr[key_middle], arr[end]);

    int cur = begin;
    int prev = begin - 1;
    while (cur < end)
    {
        if (arr[cur] < arr[end] && ++prev != cur)
        {
            swap(arr[cur], arr[prev]);
        }
        ++cur;
    }
    ++prev;
    swap(arr[prev], arr[end]);
    return prev;
}

void QuickSortNonR(int* arr, int n)
{
    int begin = 0, end = n - 1;
    stack<int> st;
    st.push(begin);
    st.push(end);
    while (!st.empty())
    {
        int right = st.top();
        st.pop();
        int left = st.top();
        st.pop();

        int key = PrevCurMethod(arr, left, right);
        if (left < key - 1)
        {
            st.push(left);
            st.push(key - 1);
        }

        if (key + 1 < right)
        {
            st.push(key + 1);
            st.push(right);
        }
    }
}

void Test()
{
    int arr[] = { 9, 5, 2, 7, 1, 4, 8, 6, 3, 0 };
    int len = sizeof(arr) / sizeof(arr[0]);
    QuickSortNonR(arr, len);
    for (auto e : arr)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    Test();
    return 0;
}

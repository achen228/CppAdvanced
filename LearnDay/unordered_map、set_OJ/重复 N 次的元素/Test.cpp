//重复 N 次的元素
//在大小为 2N 的数组 A 中有 N + 1 个不同的元素，其中有一个元素重复了 N 次。
//返回重复了 N 次的那个元素。
//输入：[1, 2, 3, 3]
//输出：3
//输入：[2, 1, 2, 5, 3, 2]
//输出：2
class Solution
{
public:
    int repeatedNTimes(vector<int>& A)
    {
        unordered_map<int, int> countMap;
        for (auto& e : A)
        {
            countMap[e]++;
        }

        int N = A.size() / 2;
        for (auto& e : countMap)
        {
            if (e.second == N)
            {
                return e.first;
            }
        }
        return -1;
    }
};

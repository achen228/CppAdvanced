//存在重复元素
//给定一个整数数组，判断是否存在重复元素。
//如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
//输入: [1, 2, 3, 1]
//输出 : true
//输入 : [1, 2, 3, 4]
//输出 : false
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map<int, int> m;
        for (auto e : nums)
        {
            m[e]++;
        }

        for (auto e : m)
        {
            if (e.second > 1)
            {
                return true;
            }
        }
        return false;
    }
};

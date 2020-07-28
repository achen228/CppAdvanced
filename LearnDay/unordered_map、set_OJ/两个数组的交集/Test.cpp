//两个数组的交集
//给定两个数组，编写一个函数来计算它们的交集。
//输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//输出：[2]
//输入：nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//输出：[9, 4]
class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> us1;
        for (auto e : nums1)
        {
            us1.insert(e);
        }

        unordered_set<int> us2;
        for (auto e : nums2)
        {
            us2.insert(e);
        }

        vector<int> v;
        for (auto e : us1)
        {
            if (us2.find(e) != us2.end())
            {
                v.push_back(e);
            }
        }
        return v;
    }
};

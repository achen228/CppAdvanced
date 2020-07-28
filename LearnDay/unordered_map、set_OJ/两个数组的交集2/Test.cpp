//两个数组的交集2
//给定两个数组，编写一个函数来计算它们的交集。
//输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//输出：[2, 2]
//输入：nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//输出：[4, 9]
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> v;
        // 创建一个哈希表
        unordered_map<int, int> m;

        // 在哈希表中存储数组nums1
        for (auto e : nums1)
        {
            m[e]++;
        }
            
        // 在数组nums2中查找
        for (auto e : nums2)
        {
            // 在哈希表（nums1）中存在且个数大于等于1
            if (m.count(e) != 0 && m[e])
            {
                v.push_back(e);
                m[e]--;
            }

        }
        return v;
    }
};

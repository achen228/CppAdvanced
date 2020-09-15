//使用set中的count判断
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> s;
        for (auto e : nums)
        {
            if (s.count(e))
            {
                return e;
            }
            else
            {
                s.insert(e);
            }
        }
        return -1;
    }
};


//先排序，后查找
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1])
            {
                return nums[i];
            }
        }
        return -1;
    }
};

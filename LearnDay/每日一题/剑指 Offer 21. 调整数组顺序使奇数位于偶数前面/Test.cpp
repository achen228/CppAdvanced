// 常规思路，暴力遍历，效率低
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1)
        {
            return nums;
        }
        
        vector<int> tmp;
        tmp.reserve(nums.size());
        for(size_t i = 0; i < nums.size(); i++)
        {
            std::vector<int>::iterator it = tmp.begin();
            if(nums[i] % 2 == 0)
            {
                tmp.push_back(nums[i]);
            }
            else
            {
                tmp.insert(it, nums[i]);
            }
        }
        nums = tmp;
        return nums;
    }
};


// 利用一前一后两个类指针遍历交换
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1)
            return nums;
        
        int begin = 0, end = nums.size() -  1;
        while(begin < end)
        {
            while(begin < end && (nums[begin] & 1) != 0)
                begin++;
            while(begin < end && (nums[end] & 1) == 0)
                end--;
            if(begin < end)
            {
                std::swap(nums[begin], nums[end]);
            }
        }
        return nums;
    }
};

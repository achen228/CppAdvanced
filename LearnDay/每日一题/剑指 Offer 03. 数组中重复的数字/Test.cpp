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

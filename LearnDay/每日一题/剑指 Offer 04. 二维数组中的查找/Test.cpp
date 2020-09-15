//暴力搜索匹配解法
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
        {
            return false;
        }

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == target)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

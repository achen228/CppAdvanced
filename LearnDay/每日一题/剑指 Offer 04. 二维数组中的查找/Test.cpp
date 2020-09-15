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


//时间复杂度O(m + n)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
        {
            return false;
        }

        int rowsize = matrix.size(), colsize = matrix[0].size();
        int row = 0, col = colsize - 1;
        while(row < rowsize && col >= 0)
        {
            //从矩阵的右上角开始匹配，如果等于target，则返回true
            if(matrix[row][col] == target)
            {
                return true;
            }
            //如果小于target，说明这一行都比target小，row向下移动一行
            else if(matrix[row][col] < target)
            {
                row++;
            }
            //如果大于target，说明这一列都比target大，col向左移动一列
            else
            {
                col--;
            }
        }

        return false;
    }
};

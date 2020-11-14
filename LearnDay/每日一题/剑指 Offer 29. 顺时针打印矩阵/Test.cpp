class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return vector<int>();
        
        int col = matrix[0].size();
        int row = matrix.size();
        vector<int> res;
        // 每个圈的起点，且起点的x、y相等
        int pivot = 0;
        // 随便画几个矩阵就能发现这么一个规律：
        // 最内圈（最后一圈）的pivot的x值乘2（或者y值乘2），会既小于m又小于n
        while(pivot * 2 < col && pivot * 2 < row)
        {
            // 循环调用loop，遍历每个圈
            loop(matrix, col, row, pivot, res);
            ++pivot;
        }
        return res;
    }

    void loop(vector<vector<int>>& matrix, int col, int row, int pivot, vector<int>& res)
    {
        int colEnd = col - 1 - pivot;
        int rowEnd = row - 1 - pivot;
        // 从左到右打印一行
        for(int i = pivot; i <= colEnd; ++i)
        {
            res.push_back(matrix[pivot][i]);
        }
        // 最内圈至少两行一列
        if(rowEnd > pivot)
        {
            // 从上到下打印一行
            for(int i = pivot + 1; i <= rowEnd; ++i)
            {
                res.push_back(matrix[i][colEnd]);
            }
        }
        // 最内圈至少两行两列
        if(rowEnd > pivot && colEnd > pivot)
        {
            // 从右到左打印一行
            for(int i = colEnd - 1; i >= pivot; --i)
            {
                res.push_back(matrix[rowEnd][i]);
            }
        }
        // 最内圈至少三行两列
        if(rowEnd > pivot + 1 && colEnd > pivot)
        {
            // 从下到上打印一行
            for(int i = rowEnd - 1; i > pivot; --i)
            {
                res.push_back(matrix[i][pivot]);
            }
        }
    }
};

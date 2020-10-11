class Solution {
public:
    int getSum(int num)
    {
        if(num < 10)
        {
            return num;
        }

        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int dfs(vector<vector<bool>>& valid, int m, int n, int row, int col, int k)
    {
        // 获取坐标的数位之和
        int sum = getSum(row) + getSum(col);
        // 如果行或列越界，数位之和大于k，该位置已被访问，就返回
        if(row >= m || col >=n || sum > k || !valid[row][col])
        {
            return 0;
        }
        // 若该位置合法，将该位置标记为已访问状态 false
        valid[row][col] = false;
        // 深度优先搜索递归遍历每个位置
        return 1 + dfs(valid, m, n, row + 1, col, k) + dfs(valid, m, n, row, col + 1, k);
    }

    int movingCount(int m, int n, int k) {
        if(k == 0)
        {
            return 1;
        }

        // 记录该位置是否被访问过
        vector<vector<bool>> valid(m, vector<bool>(n, true));
        return dfs(valid, m, n, 0, 0, k);
    }
};

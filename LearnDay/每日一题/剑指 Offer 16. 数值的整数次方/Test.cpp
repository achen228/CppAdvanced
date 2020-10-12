// 快速幂算法
// 常规思路会超出时间限制
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1.0 || n == 0)
        {
            return 1.0;
        }

        // 必须是long，否则如果 n = INT_MIN，-n就会越界
        long tmp = n;
        if(n < 0)
        {
            x = 1 / x;
            tmp = -tmp;
        }
        double ret = 1.0;
        while(tmp)
        {
            if(tmp & 1) // 奇数时执行如下累乘
            {
                ret *= x;
            }
            x *= x;
            tmp = tmp >> 1;
        }
        return ret;
    }
};

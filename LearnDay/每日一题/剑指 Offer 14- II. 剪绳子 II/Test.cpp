class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3)
        {
            return n - 1;
        }
        if(n == 4)
        {
            return n;
        }

        long ret = 1;
        while(n > 4)
        {
            ret *= 3;
            ret %= 1000000007;
            n -= 3;
        }
        // 循环出来的n只可能是2，3，4，而他们和其它部分的最大乘积就是自己本身
        return ret * n % 1000000007;
    }
};

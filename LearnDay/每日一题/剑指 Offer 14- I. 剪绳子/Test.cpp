// 解题思路
// 通过观察可以发现，当 n >= 5 时，应尽可能剪出长度为3的绳子，这样会使乘积最大
// 当 n == 4 时，我们不用剪出长度为3的绳子，可以发现 2 * 2 > 3 * 1，应剪出长度为2的
// 因为 n > 1 的，则观察发现 n == 2 || n == 3 时， 乘积为 n - 1
// 所以可以用绳长 n % 3(n >= 4)，则会有三种情况：n % 3 = 0, 1, 2
//  0：直接 return pow(3, n/3);
//  1：这个多出来的1应该和最后一个3拼成4，2*2，再与前面的相乘，即 return pow(3, n/3 - 1)*4
//  2：说明最后多出来一个 2，直接与前面的结果相乘，return pow(3, n/3 - 1)*2

class Solution {
public:
    int cuttingRope(int n) {
        if(n < 4)
        {
            return n - 1;
        }

        int count3 = n / 3;
        if(n % 3 == 0)
        {
            return pow(3, count3);
        }
        else if(n % 3 == 1)
        {
            count3--;
            return pow(3, count3) * 4;
        }
        else if(n % 3 == 2)
        {
            return pow(3, count3) * 2;
        }
        
        return -1;
    }
};

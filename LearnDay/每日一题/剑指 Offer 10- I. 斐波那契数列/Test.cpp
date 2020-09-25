class Solution {
public:
    int fib(int n) {
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            return 1;
        }

        int sum = 0, f0 = 0, f1 = 1;
        while(n >= 2)
        {
            sum = (f0 + f1) % 1000000007;
            f0 = f1;
            f1 = sum;
            n--;
        }

        return sum;
    }
};

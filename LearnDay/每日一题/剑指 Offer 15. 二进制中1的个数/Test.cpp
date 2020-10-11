// 解法一：
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0)
        {
            if(n & 1)
            {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};

// 解法二：
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0)
        {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};

// 解法三：
class Solution {
public:
    int hammingWeight(uint32_t n) {
        // 位图库函数调用
        return ((bitset<32>)n).count();
    }
};

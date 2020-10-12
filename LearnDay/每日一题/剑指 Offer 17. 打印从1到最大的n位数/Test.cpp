// 不考虑大数问题常规思路：
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> v;
        if(n == 0)
        {
            return v;
        }

        int max = 0;
        int tmp = 9;
        while(n)
        {
            max = tmp;
            tmp = tmp * 10 + 9;
            n--;
        }
        for(int i = 1; i <= max; i++)
        {
            v.push_back(i);
        }
        return v;
    }
};


// 根据返回值 int 说明最大的 n 位十进制数不会是大数
// 但是如果我们考虑大数问题呢？
class Solution {
public:
    vector<int> output;

    // 用于向 ouutput 中添加元素，如 "010"，添加的就是 10，舍去最前面的0
    void inputNumbers(string s)
    {
        bool isUnwantedZero = true;
        string tmp;
        for(int i = 0; i < s.length(); i++)
        {
            if(isUnwantedZero && s[i] != '0') // 如果是 0 就不会添加进去
            {
                isUnwantedZero = false;
            }
            if(!isUnwantedZero)
            {
                tmp += s[i];
            }
        }
        // 需要判断 tmp 是否为空，为空 stoi 函数会报错
        // 其实 stoi 函数会自动舍去字符串前面的无用0，不需要上述手动判断添加
        if(s != "")
            output.push_back(stoi(s));
    }

    // 用于累加过程的函数，且判断是否越界。如 n = 3时，999 + 1 = 1000 越界
    bool overFlow(string& s)
    {
        bool isOverFlow = false;
        int carry = 0; // carry 表示进位   
        for(int i = s.length() - 1; i >= 0; i--)
        {
            int current = s[i] - '0' + carry; // current 表示当前的这次操作
            if(i == s.length() - 1) // 如果 i 此时在个位，carry++
            {
                current++;
            }

            if(current >= 10)
            {
                if(i == 0)
                {
                    //表示 i 已经在最大的那一位了，再累加就会越界
                    isOverFlow = true;
                }
                else
                {
                    // 只是普通进位，current从9变成10
                    carry = 1;
                    s[i] = current - 10 + '0';
                }
            }
            else
            {
                // 如果没有进位，更新s[i]的值，跳出循环，向output中添加元素
                s[i] = current + '0';
                break;
            }
        }
        return isOverFlow;
    }

    vector<int> printNumbers(int n) {
        if(n == 0)
        {
            return vector<int>(0);
        }

        string s(n, '0');
        while(!overFlow(s))
        {
            inputNumbers(s);
        }
        return output;
    }
};

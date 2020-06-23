//有效括号匹配。
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意:空字符串可被认为是有效字符串。

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if (s[i] == ']')
            {
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == ')')
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == '}')
            {
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Solution2 {
public:
    bool isValid(string s)
    {
        const char* logo[3] = { "()", "[]", "{}" };
        stack<char> st;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }

                for (int j = 0; j < 3; j++)
                {
                    if (s[i] == logo[j][1] && st.top() != logo[j][0])
                    {
                        return false;
                    }
                }
                st.pop();
            }
        }
        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution2 so;
    string str = "[({})]";
    int ret = so.isValid(str);
    printf("%d\n", ret);
    return 0;
}

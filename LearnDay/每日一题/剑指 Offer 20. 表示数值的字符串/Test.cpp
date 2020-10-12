//1.从第一个不为空格的字符到最后一个不为空格的字符，中间不得出现任何空格。
//2.'.' 只能出现一次，而且不可以出现在 'e' 的后面，且紧贴着 '.' 的左边或者右边或者两边必须有数字（也就是不能是一个单独的 '.'）。
//3.'e' 只能出现一次，而且紧贴着 'e' 的左边必须有数字。
//4.'+' 和 '-' 要么在第一位，要么紧随 'e' 后。
//5.最后一位不可以是 'e' 或 '+' 或 '-'。

class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) 
            return false;
        while(s.length() > 0 && s[0] == ' ')
            s.erase(0, 1);
        while(s.length() > 0 && s[s.length() - 1] == ' ')
            s.erase(s.length() - 1, 1);
        if(s.length() == 0)
            return false;
        bool isNumber = false, isE = false, isDoc = false;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
                return false;
            else if(s[i] >= '0' && s[i] <= '9')
                isNumber = true;
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(isE || !isNumber || i == s.length() - 1)
                    return false;
                s[i] = 'e';
                isE = true;
            }
            else if(s[i] == '+' || s[i] == '-')
            {
                if((i > 0 && s[i - 1] != 'e') || i == s.length() - 1)
                    return false;
            }
            else if(s[i] == '.')
            {
                if(isDoc || isE || (i == s.length() - 1 && !isNumber))
                    return false;
                isDoc = true;
            }
            else 
                return false;
        }
        return true;
    }
};

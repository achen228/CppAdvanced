//时间复杂度 O(N) ： 遍历统计、遍历修改皆使用 O(N) 时间。
//空间复杂度 O(1) ： 由于是原地扩展 s 长度，因此使用 O(1) 额外空间。
class Solution {
public:
    string replaceSpace(string s) {
        //字符串长度
        int len = s.size();

        //统计空格的个数
        int count = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == ' ')
            {
                count++;
            }
        }
        
        //修改字符串的长度
        s.resize(len + 2 * count);

        //倒序遍历修改空格
        for(int i = len - 1, j = s.size() - 1; i < j; i--, j--)
        {
            if(s[i] != ' ')
            {
                s[j] = s[i];
            }
            else
            {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j = j - 2;
            }
        }

        return s;
    }
};

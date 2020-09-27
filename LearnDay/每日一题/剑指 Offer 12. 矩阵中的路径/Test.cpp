class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())
        {
            return false;
        }
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                //使用回溯法寻找
                if(Backtrack(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool Backtrack(vector<vector<char>>& board, string word, int i, int j, int w)
    {
        //越界问题以及当前元素不匹配，返回false
        if(i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1 || board[i][j] != word[w])
        {
            return false;
        }

        //如果是word中最后一个元素了，也就没有必要进行下面的回溯寻找了，直接返回true，因为上一步已经判断了当前元素是匹配
        if(w == word.size() - 1)
        {
            return true;
        }

        //将当前元素标志位'\0'，防止下面的回溯再让它参与比较
        char temp = board[i][j];
        board[i][j] = '\0';

        if(Backtrack(board, word, i - 1, j, w + 1)
        || Backtrack(board, word, i + 1, j, w + 1)
        || Backtrack(board, word, i, j - 1, w + 1)
        || Backtrack(board, word, i, j + 1, w + 1))
        {
            return true;
        }

        //表示从board[i][j]开始的这个元素没有匹配符合的路径，将标志位'\0'恢复为原来的值temp
        board[i][j] = temp;
        return false;
    }
};

//LC 79
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
// The same letter cell may not be used more than once.


class Solution
{
public:
    bool helper(int x, int y, int pos, vector<vector<char>> &board, string &word)
    {
        if (pos >= word.size())
            return true;
        if (x == board.size() || y == board[0].size() || x < 0 || y < 0)
            return false;
        if (board[x][y] != word[pos])
            return false;
        char alpha = board[x][y];
        board[x][y] = '*';
        if (helper(x + 1, y, pos + 1, board, word))
            return true;
        if (helper(x, y + 1, pos + 1, board, word))
            return true;
        if (helper(x - 1, y, pos + 1, board, word))
            return true;
        if (helper(x, y - 1, pos + 1, board, word))
            return true;
        board[x][y] = alpha;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        bool x;
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    x = helper(i, j, 0, board, word);
                    if (x == true)
                        return true;
                }
            }
        }
        return false;
    }
};

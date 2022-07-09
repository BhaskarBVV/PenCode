// https://leetcode.com/problems/sudoku-solver/
class Solution
{
public:
    bool is_safe(int i, int j, char c, vector<vector<char>> &board)
    {
        for (int x = 0; x < 9; x++)
        {
            if (board[i][x] == c)
                return false;
            if (board[x][j] == c)
                return false;
            if (board[3 * (i / 3) + x / 3][3 * (j / 3) + x % 3] == c)
                return false;
        }
        return true;
    }
    void helper(int i, int j, vector<vector<char>> &board, vector<vector<char>> &ans)
    {
        if (i == board.size() && j == 0)
        {
            ans = board;
            return;
        }
        int ni, nj;
        if (j == board[0].size())
        {
            ni = i + 1;
            nj = 0;
        }
        else
        {
            ni = i;
            nj = j + 1;
        }
        if (board[i][j] != '.')
        {
            helper(ni, nj, board, ans);
        }
        else
        {
            for (int k = 1; k <= 9; k++)
            {
                if (is_safe(i, j, k + '0', board))
                {
                    board[i][j] = k + '0';
                    helper(ni, nj, board, ans);
                    if (ans[0][0] != '.')
                        return;
                    board[i][j] = '.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<char>> ans(board.size(), vector<char>(board.size(), '.'));
        helper(0, 0, board, ans);
        board = ans;
    }
};

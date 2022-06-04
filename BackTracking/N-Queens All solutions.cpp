class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<char>> chess(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        solve(chess, 0, ans);
        return ans;
    }

    void solve(vector<vector<char>> &chess, int row, vector<vector<string>> &ans)
    {
        if (row == chess.size())
        {
          //pushing the current solution to ans.
            vector<string> temp;
            string s = "";
            for (auto it : chess)
            {
                for (auto i : it)
                    s += i;
                temp.push_back(s);
                s = "";
            }
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < chess.size(); i++) // iterating over every column of the row, ans if the current position is safe, then place the queen.
          //and in same solution, move to next row by recursion.
        {
            if (is_pos_safe(chess, row, i))
            {
                chess[row][i] = 'Q';
                solve(chess, row + 1, ans);
                chess[row][i] = '.';
            }
        }
    }

    bool is_pos_safe(vector<vector<char>> &chess, int row, int col)
    {
      
      // checking vertical top
        for (int i = row - 1; i >= 0; i--)
            if (chess[i][col] == 'Q')
                return false;
      
      // checking left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (chess[i][j] == 'Q')
                return false;
      
      //checking right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++)
            if (chess[i][j] == 'Q')
                return false;
      
        return true;
    }
};

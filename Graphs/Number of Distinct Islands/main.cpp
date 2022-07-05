class Solution
{
public:
    void helper(string &temp, int i, int j, vector<vector<int>> &grid, char dir)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        {
            return;
        }
        grid[i][j] = 0;
        temp += dir;
        helper(temp, i + 1, j, grid, 'D');
        helper(temp, i - 1, j, grid, 'U');
        helper(temp, i, j + 1, grid, 'R');
        helper(temp, i, j - 1, grid, 'L');
        temp += 'B'; //it is very important to add something while backtracking, bcz to different shaped islands may give the same string, (Refer to image)
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        set<string> ans;
        string temp = "";
        char dir;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    temp = "S";
                    helper(temp, i, j, grid, dir);
                    ans.insert(temp);
                    // cout<<temp<<endl;
                }
            }
        }
        return ans.size();
    }
};

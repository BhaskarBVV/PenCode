class Solution
{
public:
    void getInQueue(int i, int j, queue<pair<int, int>> &q, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        if (i >= grid.size() || i < 0 || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j] == true)
            return;
        vis[i][j] = true;
        q.push({i, j});
        getInQueue(i - 1, j, q, grid, vis);
        getInQueue(i + 1, j, q, grid, vis);
        getInQueue(i, j + 1, q, grid, vis);
        getInQueue(i, j - 1, q, grid, vis);
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        bool flag = true;
        for (int i = 0; i < grid.size() && flag; i++)
        {
            for (int j = 0; j < grid[0].size() && flag; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == false)
                {
                    getInQueue(i, j, q, grid, vis);
                    flag = false;
                }
            }
        }
        int dst = -1, size = 0;
        int dir[][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        pair<int, int> temp;
        while (!q.empty())
        {
            size = q.size();
            dst++;
            while (size--)
            {
                temp = q.front();
                q.pop();
                int i, j;
                for (int k = 0; k < 4; k++)
                {
                    i = temp.first + dir[k][0];
                    j = temp.second + dir[k][1];
                    if (i < grid.size() && i >= 0 && j < grid[0].size() && j >= 0)
                    {
                        if (vis[i][j] == false)
                        {
                            if (grid[i][j] == 1)
                                return dst;
                            else
                                q.push({i, j});
                            vis[i][j] = true;
                        }
                    }
                }
            }
        }
        return dst;
    }
};

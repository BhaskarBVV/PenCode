#include <bits/stdc++.h>
using namespace std;
void del(vector<vector<int>> &grid, int i, int j)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        return;
    grid[i][j] = 0; // del krte main har baar, wo poora island/ that conneected cells ko 0 (according to question, doosri given value, jis pr dfs ni ho rhi hai) main convert krdo(easiest way to delete), taaki wo aage dobara "validate_is_Subisland" main call na ho jayein, (stack overflow ho jaayegi, wo bar bar wahin ghoomta rahega)
    del(grid, i + 1, j);
    del(grid, i, j + 1);
    del(grid, i - 1, j);
    del(grid, i, j - 1);
}
void validate_is_Subisland(vector<vector<int>> &a, vector<vector<int>> &b, int i, int j)
{
    if (i < 0 || i >= a.size() || j < 0 || j >= a[0].size() || (a[i][j] == 0 && b[i][j] == 0) || (a[i][j] == 1 && (b[i][j] == 0 || b[i][j] == 2)))
        return;
    if (a[i][j] == 0 && b[i][j] == 1) // condition when ith island of gird 2 does not forms as a sub-island of grid 1.
    {
        del(b, i, j); // hence, erdicate that island of grid2 from the count of subislands,
                      // by marking all cells of that island to 0 as indication, that this island will not be counted.
                      // poora island grid2 ka toh traverse ni hua hoga, kuch cells 1 honge(jo traverse ni hue hain abhi)
                      // and kuch 2 honge(jo traverse hue hain and valid subisland bana rhe hain)
        return;
    }
    // jab tak hume ye dekh paa rhe hain ki traversed island of grid2 ka grid1 ke island ke andar hi hai ya overlapping hai
    // tab tab b[i][j]=2, krdo taaki pata rhe yahan tak ka island grid1 ke island ka sub-Island hai,
    // aur jahan overlapping ni hua ya grid1 ke island se baahr jaa rha hai, toh us poore grid1 ke island ko del kr do
    b[i][j] = 2;
    validate_is_Subisland(a, b, i + 1, j);
    validate_is_Subisland(a, b, i - 1, j);
    validate_is_Subisland(a, b, i, j + 1);
    validate_is_Subisland(a, b, i, j - 1);
}
void count(vector<vector<int>> &grid, int i, int j)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 2)
        return;
    grid[i][j] = 0;
    count(grid, i + 1, j);
    count(grid, i, j + 1);
    count(grid, i - 1, j);
    count(grid, i, j - 1);
}
int countSubIslands(vector<vector<int>> &a, vector<vector<int>> &b)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            if (a[i][j] == 1 && b[i][j] == 1)
                validate_is_Subisland(a, b, i, j); // check krlo poora islnad gird2 ka subIsland ban bhi rha hai ya ni grid1 ke island ka
        }
    }
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            if (b[i][j] == 2)
            {
                cnt++;
                count(b, i, j);
            }
        }
    }
    return cnt;
}

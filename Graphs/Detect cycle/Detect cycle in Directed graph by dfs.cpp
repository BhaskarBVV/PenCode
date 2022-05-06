#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void check_cycle(int i, vector<int> adj[], vector<bool> &vis, vector<bool> &dfs_vis, bool &cycle)
    {

        if (dfs_vis[i] == true)
        {
            cycle = true;
            return;
        }
        dfs_vis[i] = true;
        for (auto it : adj[i])
        {
            if (vis[it] == false)
            {
                check_cycle(it, adj, vis, dfs_vis, cycle);
                if (cycle)
                    return;
            }
        }
        dfs_vis[i] = false;
    }
    bool is_cycle_present(int n, vector<vector<int>> &Edges)
    {
        vector<int> adj[n];
        for (auto it : Edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<bool> vis(n, false);
        vector<bool> dfs_vis(n, false);

        bool cycle = false;
        for (int i = 0; i < n; i++)
        {
            vis[i] = true;
            check_cycle(i, adj, vis, dfs_vis, cycle);
            if (cycle)
                return false;
        }
        return true;
    }
};

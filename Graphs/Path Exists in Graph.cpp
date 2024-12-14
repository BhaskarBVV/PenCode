// Input: n = 3, edges = [[0,1],[1,2],[2,0]], start = 0, end = 2
// Output: true
// Explanation: There are two paths from vertex 0 to vertex 2:
// - 0 → 1 → 2
// - 0 → 2

// Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], start = 0, end = 5
// Output: false
// Explanation: There is no path from vertex 0 to vertex 5.


class Solution
{
public:
    void dfs(vector<int> adj[], int end, int node, vector<bool> &vis, bool &flag)
    {
        if (node == end)
        {
            flag = true;
            return;
        }
        if (vis[node])
            return;
        vis[node] = true;
        for (auto element : adj[node])
            if (flag)
                return;
            else
                dfs(adj, end, element, vis, flag);
    }
    bool validPath(int n, vector<vector<int>> &edges, int start, int end)
    {

        vector<int> adj[n];
        vector<bool> vis(n, false);
        bool flag = false;
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(adj, end, start, vis, flag);
        return flag;
    }
};

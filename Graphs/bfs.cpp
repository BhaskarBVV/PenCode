vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    queue<int> q;
    q.push(0);
    vector<bool> vis(V, false);
    vis[0] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (auto it : adj[temp])
        {
            if (vis[it] == false)
            {
                q.push(it);
                vis[it] = true;
            }
        }
    }
    return ans;
}

vector<int> bfsOfGraph(int v, vector<int> adj[])
{
    vector<int> is_tra(v + 1, 0);
    vector<int> bfs;
    queue<int> q;
    q.push(0);
    int x;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        if (is_tra[x] == 0)
        {
            is_tra[x] = 1;
            bfs.push_back(x);
            for (auto it : adj[x])
            {
                if (is_tra[it] == 0)
                    q.push(it);
            }
        }
    }
    return bfs;
}

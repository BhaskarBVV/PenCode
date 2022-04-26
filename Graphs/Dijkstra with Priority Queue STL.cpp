void dfs(vector<int> &ans, int i, vector<int> &parent, int &flag)
{
    // cout << i << endl;
    ans.push_back(i);
    if (i == 1)
        return;
    if (i == INT_MAX)
    {
        flag = 1;
        return;
    }
    dfs(ans, parent[i], parent, flag);
}
struct comp
{
    bool operator()(pair<int, int> const &p1, pair<int, int> const &p2)
    {
        return p1.second > p2.second;
    }
};
void solve()
{
    int n, m, a, b, wt;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    while (m--)
    {
        cin >> a >> b >> wt;
        adj[a - 1].pb({b - 1, wt});
        adj[b - 1].pb({a - 1, wt});
    }
    vector<ll> val(n, LONG_LONG_MAX);
    vector<int> parent(n + 1, INT_MAX);
    parent[0] = -1;
    val[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    vector<bool> vis(n, false);
    // cout << "A" << endl;
    pq.push({0, 0});
    while (!pq.empty())
    {
        pair<int, int> temp = pq.top();
        // cout << temp.first << endl;
        pq.pop();
        vis[temp.first] = true;
        // cout << u << endl;
        for (auto it : adj[temp.first])
        {
            if (vis[it.first] == false)
            {
                if (it.second + val[temp.first] < val[it.first])
                {
                    val[it.first] = val[temp.first] + it.second;
                    pq.push({it.first, val[it.first]});
                    parent[it.first + 1] = temp.first + 1;  //indexing ka chakkar 0 ni hoga isme node koi, par maine 0 maan ke kr liye hai, toh actual parent toh +1 ho hoga na
                }
            }
        }
    }
    // cout << "B" << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Parent of " << i << ":" << parent[i] << "\n";
    // }
    vector<int> ans;
    int flag = 0;
    dfs(ans, n, parent, flag);
    reverse(ans.begin(), ans.end());
    if (*ans.begin() != 1 || flag == 1)
    {
        cout << -1;
        return;
    }
    for (auto it : ans)
        cout << it << " ";
}

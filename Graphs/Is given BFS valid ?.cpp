void solve()
{
    int n, a, b;
    cin >> n;

    map<int, vector<int>> mp;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        mp[a].pb(b);
        mp[b].pb(a);
    }

    int given_bfs[n];
    for (int i = 0; i < n; i++)
        cin >> given_bfs[i];

    bool vis[n + 1]{false};

    // for (int i = 0; i < n; i++)
    //     cout << given_bfs[i] << "--" << vis[given_bfs[i]] << endl;

    queue<int> q;
    q.push(1);

    int temp;
    int tra_in = 1;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        vis[temp] = true;

        set<int> s;
        for (auto it : mp[temp])
            if (vis[it] == false)
                s.insert(it);

        for (int i = 0; i < s.size(); i++)
        {
            if (s.find(given_bfs[tra_in]) != s.end() && vis[given_bfs[tra_in]] == false)
            {
                q.push(given_bfs[tra_in]);
                tra_in++;
            }
            else
            {
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";
    return;
}

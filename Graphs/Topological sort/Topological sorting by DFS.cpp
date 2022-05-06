#include <bits/stdc++.h>
using namespace std;
void get_topo_by_dfs(int i, vector<bool> &vis, stack<int> &s, vector<int> adj[])
{
    vis[i] = true;
    for (auto it : adj[i])
    {
        if (vis[it] == false)
            get_topo_by_dfs(it, vis, s, adj);
    }
    s.push(i);
}
// Topological sorting can be done only for directed Acyclic Graph..
// Multiple ways possible....
int main()
{
    int n, e, a, b;
    cout << "Enter the number of vertices : ";
    cin >> n;
    cout << "Enter the number of Edges : ";
    cin >> e;
    vector<int> adj[n];
    cout << "Enter the Edges:\n ";
    while (e--)
    {
        cout << "Enter the Edge : ";
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<bool> vis(n, false);
    vector<int> ans;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
            get_topo_by_dfs(i, vis, s, adj);
    }
    cout << "\nTopological sorting will be : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

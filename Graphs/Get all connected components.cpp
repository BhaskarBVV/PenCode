void dfs(vector<int> graph[], vector<int> &path, int i, vector<vector<int>> &ans, vector<bool> &vis)
{
    vis[i] = true;
    for (auto it : graph[i])
    {
        if (vis[it] == false)
        {
            path.push_back(it);
            dfs(graph, path, it, ans, vis);
        }
    }
}
int main()
{

    //----above code-----
    //-----n=no. of vertices----
    vector<vector<int>> all_components;
    vector<int> comp;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            comp.clear();
            comp.push_back(i);
            dfs(adj, comp, i, all_components, vis);
            all_components.push_back(comp);
        }
    }
    //------below code-----
    //----print all components---
}

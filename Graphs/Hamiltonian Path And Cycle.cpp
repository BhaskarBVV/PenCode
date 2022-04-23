#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src = 0;
    int nbr = 0;
    int wt = 0;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};
void Hamil_path_or_cycle(int i, int src, vector<string> &ans, vector<bool> vis, vector<vector<Edge>> &adj, string str)
{
    // (i) is the cuurent node.
    // (src) was the original starting node.
    vis[i] = true;
    if (str.size() == adj.size())
    {
        for (auto it : adj[i])
        {
            // checking if this path forms a cycle.
            // don't check cycle by verifying if(i==src). NO.
            // for cycle, check if the size of string == all vertices and current node has any node that was our original source node.
            // bcz, cycle ends at the starting node, not path.
            if (it.nbr == src)
            {
                str += '*'; // * is for cycle
                ans.push_back(str);
                return;
            }
        }
        str += '.'; // "." is for path.
        ans.push_back(str);
    }
    for (auto it : adj[i])
    {
        if (vis[it.nbr] == false)
        {
            Hamil_path_or_cycle(it.nbr, src, ans, vis, adj, str + to_string(it.nbr));
        }
    }
}
int main()
{
    cout << "Enter the number of vertices : ";
    int n;
    cin >> n;
    vector<vector<Edge>> graph(n, vector<Edge>());

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(Edge(u, v, w));
        graph[v].push_back(Edge(v, u, w));
    }
    cout << "Enter the source node : ";
    int src;
    cin >> src;

    vector<bool> vis(n, false);
    vector<string> ans;
    Hamil_path_or_cycle(src, src, ans, vis, graph, to_string(src));
    for (auto it : ans)
        cout << it << endl;
    return 0;
}

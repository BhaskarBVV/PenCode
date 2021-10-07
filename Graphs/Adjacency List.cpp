//Bhaskar Varshney
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m, u, v;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the nodes : ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        for (auto it : adj[i])
            cout << it << "->";
        cout << endl;
    }
}

// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
// Topological sort -> reverse edges -> dfs

class Solution
{
private:
// The same dfs function can be used in both topological sort and normal dfs
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> *preTopoSort = nullptr)
    {
        if (visited[node] == true)
            return;
        visited[node] = true;
        for (auto nbr : adj[node])
        {
            dfs(nbr, adj, visited, preTopoSort);
        }
        if (preTopoSort != nullptr)
            preTopoSort->push(node);
    }

    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        int V = adj.size();
        stack<int> pre_topo_sort;
        vector<bool> visited(V, false);
        for (int node = 0; node < V; node++)
        {
            if (visited[node] == false)
            {
                dfs(node, adj, visited, &pre_topo_sort);
            }
        }
        vector<int> topoSort;
        while (!pre_topo_sort.empty())
        {
            topoSort.push_back(pre_topo_sort.top());
            pre_topo_sort.pop();
        }
        return topoSort;
    }

    vector<vector<int>> reverseEdges(vector<vector<int>> &adj)
    {
        vector<vector<int>> newAdj(adj.size());
        for (int node = 0; node < adj.size(); node++)
        {
            for (auto nbr : adj[node])
            {
                newAdj[nbr].push_back(node);
            }
        }
        return newAdj;
    }

public:
    int kosaraju(vector<vector<int>> &adj)
    {
        vector<int> topoSort = topologicalSort(adj);
        adj = reverseEdges(adj);
        vector<bool> visited(adj.size(), false);
        int connectedComponents = 0;
        for (auto node : topoSort)
        {
            if (visited[node] == false)
            {
                dfs(node, adj, visited);
                connectedComponents++;
            }
        }
        return connectedComponents;
    }
};

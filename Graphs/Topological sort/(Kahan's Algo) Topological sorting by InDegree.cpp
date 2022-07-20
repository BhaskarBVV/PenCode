vector<int> topoSort(int V, vector<int> adj[])
    {
        int n = V;
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
                indegree[it]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        int temp;
        vector<int> ans;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            ans.push_back(temp);
            for (auto it : adj[temp])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
  
  // in case if it is not mentioned that the given graph is acyclic, 
  // use below to check cycle.
  // if graph is cyclic topologiacl sort doesn't exist, so return {} list.
        for (auto it : indegree)
            if (it != 0)
                return {};
        return ans;
    }

void dfs(int i, vector<bool> &visited, vector<int>&v, vector<int> adj[])
    {
        v.push_back(i);
        visited[i]=true;
        for(auto it: adj[i])
        if(visited[it]==false)
        dfs(it,visited,v,adj);
    }
    vector<int> dfsOfGraph(int n, vector<int> adj[])    
    {
        vector<int>v;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++)
        if(visited[i]==false)
        dfs(i,visited,v,adj);
        return v;
    }

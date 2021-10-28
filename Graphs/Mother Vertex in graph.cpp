void dfs(int v, vector<bool>&visited, vector<int>adj[])
    {
        visited[v]=true;
        for(auto it: adj[v])
        if(visited[it]==false)
        dfs(it,visited,adj);
    }
	int findMotherVertex(int n, vector<int>adj[])
	{
	    int mv;
	    vector<bool>visited (n,false);
	    for(int i=0;i<n;i++)
	    {
	        if(visited[i]==false)
	        {dfs(i,visited,adj);
	        mv=i;}
	    }
	    fill(visited.begin(),visited.end(),false);
	    dfs(mv,visited,adj);
	    for(int i=0;i<n;i++)
	    if(visited[i]==false)
	    return -1;
	    return mv;
	}


// https://practice.geeksforgeeks.org/problems/mother-vertex/1

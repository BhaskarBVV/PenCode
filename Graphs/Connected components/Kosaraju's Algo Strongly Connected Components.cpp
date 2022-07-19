class Solution
{
public:



    void initial_dfs(int i, vector<int> adj[], stack<int> &s, vector<bool> &vis)
    {
        vis[i] = true;
        for (auto it : adj[i])
        {
            if (vis[it] == false)
            {
                initial_dfs(it, adj, s, vis);
                s.push(it);
            }
        }
    }
    
    
  
  
  
  
    
    void final_dfs(int i, vector<int> adj[], vector<bool> &vis, vector<int> &cur)
    {
        vis[i] = true;
        cur.push_back(i);
        for (auto it : adj[i])
        {
            if (vis[it] == false)
            {
                final_dfs(it, adj, vis, cur);
            }
        }
    }
  
  
  
  
  
  
  
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> s;
        vector<bool> vis(V, false);
      
//        STEP1: do dfs, and push all the nodes, while returning.
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false)
            {
                initial_dfs(i, adj, s, vis); // return krte main push krni hai nodes.
                s.push(i);                   // isliye (i) ko return krte main daal rhe hain.
            }
        }

      
      
//       STEP2: Transpose the graph.
        vector<int> adj2[V];
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                adj2[it].push_back(i);
            }
        }

      
      
//       STEP3: do dfs, by popping the value from the stack, if the popped value is already visited, then don't do its dfs.
        vector<vector<int>> strongly_conn_com;
        vector<int> cur;
        for (int i = 0; i < V; i++)
            vis[i] = false;
        int cnt = 0, temp;

      
        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            if (vis[temp] == false)
            {
                cnt++;  // Number of strongly connected components increases.
                cur.clear();
                final_dfs(temp, adj2, vis, cur);
                strongly_conn_com.push_back(cur);
            }
        }
        return cnt;
    }
};

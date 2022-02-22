// done similarly to graph coloring

class Solution {
	public:
	bool isBipartite(vector<vector<int>>& graph) 
    {			
        int n=graph.size(); 
        vector<int> col(n,-1);  
        queue<pair<int,int>> q; 
        for(int i=0;i<n;i++)
        {   
            if(col[i]==-1)
            {     
                q.push({i,1});  
                col[i]=1;       
                 while(!q.empty())
                 {
                    pair<int,int> p=q.front(); 
                    q.pop();
                    int v=p.first;         
                    int c=p.second;       
                    for(int j:graph[v])
                    {       
                        if(col[j]==c)      
                            return false;
                        if(col[j]==-1)
                        {
                            col[j]=1-col[v];
                            q.push({j,col[j]}); 
                        }
                    }
                }
            }
        }
        return true;
    }
};

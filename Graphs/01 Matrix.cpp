class pairr
{
public:
    int i, j, dst;
    pairr() {}
    pairr(int b, int c, int d)
    {
        i = b, j = c, dst = d;
    }
};


class Solution
{
public:
  
  
  
    void add(int i, int j, int dst, queue<pairr> &q, vector<vector<bool>> &vis)
    {
        if (i < 0 || j < 0 || i >= vis.size() || j >= vis[0].size() || vis[i][j])
            return;
        q.push(pairr(i, j, dst));
    }
  
  
  
  
  
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size()));
        queue<pairr> q;
      
      
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                    q.push(pairr(i,j,0));
            }
        }
      
      
        vector<vector<bool>> vis(mat.size(), vector<bool>(mat[0].size(), false));
        pairr temp;
      
      
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (vis[temp.i][temp.j] == false)
            {
                vis[temp.i][temp.j] = true;
                ans[temp.i][temp.j] = temp.dst;
                add(temp.i + 1, temp.j, temp.dst + 1, q, vis);
                add(temp.i, temp.j + 1, temp.dst + 1, q, vis);
                add(temp.i, temp.j - 1, temp.dst + 1, q, vis);
                add(temp.i - 1, temp.j, temp.dst + 1, q, vis);
            }
        }
        return ans;
    }
  
  
  
  

};

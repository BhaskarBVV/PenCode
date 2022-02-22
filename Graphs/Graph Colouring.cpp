class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &edges)
    {
        vector<int> adj[n];
        for (auto it : edges)
        {
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }
        vector<int> col(n, -1);
        col[0] = 1;
        queue<int> q;
        q.push(0);
        int temp;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            for (auto it : adj[temp])
            {
                if (col[it] == -1)
                {
                    col[it] = 1 - col[temp];
                    q.push(it);
                }
                else
                {
                    if (col[it] != 1 - col[temp])
                        return false;
                }
            }
        }
        return true;
    }
};

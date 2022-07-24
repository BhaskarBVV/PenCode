// https://leetcode.com/problems/redundant-connection/


class Solution
{
public:
    int find_par(int x, vector<int> &parent)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find_par(parent[x], parent);
    }

    void Union(int a, int b, vector<int> &rank, vector<int> &parent)
    {
        if (rank[a] == rank[b])
        {
            parent[a] = b;
            rank[b] += 1;
        }
        else if (rank[a] < rank[b])
            parent[a] = b;
        else
            parent[b] = a;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        
        int n = edges.size();
        vector<int> parent;
        
        for (int i = 0; i <= n; i++)
            parent.push_back(i);
        
        vector<int> rank(n + 1, 0);

        int x, y;

        for (auto it : edges)
        {
            x = it[0], y = it[1];
            int parX = find_par(x, parent);
            int parY = find_par(y, parent);
            
			//if both vertices belong to the same set (have same parent), means if we include the edges between these
			//vertices, they will definitely form the cycle. Hence, we will return this edge., as it will form the cycle.
			
            if (parX == parY)
                return it;
            Union(parX, parY, rank, parent);
        }

        return {};
    }
};

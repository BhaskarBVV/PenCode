class par
{
public:
    int a, b, wt;
    par() {}
    par(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        wt = c;
    }
};

class Solution
{
public:
    struct comp
    {
        bool operator()(par &a, par &b)
        {
            return a.wt > b.wt;
        }
    };

    int find_par(int a, vector<int> &parent)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find_par(parent[a], parent);
    }

    void Union(int a, int b, vector<int> &rank, vector<int> &parent)
    {
        if (a == b)
        {
            parent[a] = b;
            rank[b] += 1;
        }
        else if (rank[a] > rank[b])
        {
            parent[b] = a;
        }
        else
            parent[a] = b;
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        priority_queue<par, vector<par>, comp> pq;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                int dst = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]); // the dst is not directly given in qustion.
                pq.push(par(i, j, dst)); // If given, then directly enter (src, dest, weight) into the priority_queue (min).
            }
        }

        vector<par> ans;

        vector<int> parent;
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
            parent.push_back(i);

        par temp;
        while (!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            int par_of_src = find_par(temp.a, parent);
            int par_of_dst = find_par(temp.b, parent);
        
          
            // if two nodes do not belong to same set, than we will take this edge.
          // if the two nodes belong to the same set, then if we take this edge, it will form cycle, and hence we will not include this edge in our MST.
            if (par_of_dst != par_of_src)
            {
                ans.push_back(temp);
                Union(par_of_dst, par_of_src, rank, parent);
            }
        }

        int sum = 0;  // sum of all edges of MST.
        for (auto it : ans)
            sum += it.wt;
        return sum;
    }
};

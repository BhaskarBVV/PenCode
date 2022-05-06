#define ll long long int
class Solution
{
public:
    struct comp
    {
        bool operator()(pair<int, int> const &p1, pair<int, int> const &p2)
        {
            return p1.second > p2.second;
        }
    };
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
            //pair(node, weight)
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < points.size(); i++)
            for (int j = i + 1; j < points.size(); j++)
            {
                int x1 = points[i][0], x2 = points[j][0], y1 = points[i][1], y2 = points[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }

        vector<ll> val(n, LONG_LONG_MAX);
        val[0] = 0;
                   //pair(node, weight)
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        vector<bool> vis(n, false);
        pq.push({0, 0});
        while (!pq.empty())
        {
            pair<int, int> temp = pq.top();
            pq.pop();
            vis[temp.first] = true;
            for (auto it : adj[temp.first])
            {
                if (vis[it.first] == false)
                {
                    if (it.second < val[it.first])
                    {
                        val[it.first] = it.second;
                        pq.push({it.first, val[it.first]});
                    }
                }
            }
        }
        int sum;
        for (auto it : val)
            sum+=it;
        return sum;
    }
};

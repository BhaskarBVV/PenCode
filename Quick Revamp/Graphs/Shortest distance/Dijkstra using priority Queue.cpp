// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Edge
{
public:
    int weight;
    int node;
    Edge(int a, int b)
    {
        this->node = a;
        this->weight = b;
    }
};

struct Compare
{
    bool operator()(const Edge &a, const Edge &b)
    {
        return a.weight > b.weight; // min-heap: lower cost comes first
    }
};

class Solution
{
private:
    int getNodeWithMinDistance(int V, vector<int> &distance, vector<bool> &visited, priority_queue<Edge, vector<Edge>, Compare> &pq)
    {
        while (!pq.empty())
        {
            Edge top = pq.top();
            if (visited[top.node] == false)
                return top.node;
            pq.pop();
        }
        return -1;
    }

public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> distance(V, INT_MAX);
        distance[src] = 0;
        priority_queue<Edge, vector<Edge>, Compare> pq;
        pq.push(Edge(src, 0));

        vector<bool>visited(V, false);

        vector<int> parent(V);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        vector<vector<Edge>> adj(V, vector<Edge>());
        for (auto it : edges)
        {
            int node1 = it[0], node2 = it[1], weight = it[2];
            adj[node1].push_back(Edge(node2, weight));
        }

        int key = getNodeWithMinDistance(V, distance, visited, pq);
        while (key != -1)
        {
            visited[key] = true;
            for (auto nbr : adj[key])
            {
                if (distance[key] + nbr.weight < distance[nbr.node])
                {
                    distance[nbr.node] = distance[key] + nbr.weight;
                    parent[nbr.node] = key;
                    pq.push(Edge(nbr.node, distance[nbr.node]));
                }
            }
            key = getNodeWithMinDistance(V, distance, visited, pq);
        }
        return distance;
    }
};

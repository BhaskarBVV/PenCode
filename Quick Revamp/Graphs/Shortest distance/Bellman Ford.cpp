// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution
{
private:
    // This function performs one full relaxation over all edges
    bool relax(int src, vector<vector<int>> &edges, vector<int> &distance)
    {
        bool isDistanceUpdated = false;

        // Iterate through each edge: [from, to, weight]
        for (auto it : edges)
        {
            int node1 = it[0], node2 = it[1], weight = it[2];

            // Only proceed if the source node's distance is finite
            if (distance[node1] != 1e8 && distance[node1] + weight < distance[node2])
            {
                // A shorter path to node2 is found via node1
                distance[node2] = distance[node1] + weight;
                isDistanceUpdated = true;
            }
        }

        // Return whether any distance was updated
        return isDistanceUpdated;
    }

    // This function performs the relaxation step V-1 times
    void calculateMinDistance(int V, int src, vector<vector<int>> &edges, vector<int> &distance)
    {
        // Do V-1 passes over all edges
        for (int i = 1; i <= V - 1; i++)
        {
            relax(src, edges, distance);
        }
    }

public:
    // Main function to compute shortest paths from src using Bellman-Ford
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        // Step 1: Initialize all distances to "infinity" (here, 1e8 is used instead of INT_MAX)
        vector<int> distance(V, 1e8);
        distance[src] = 0; // Distance to source is 0

        // Step 2: Perform relaxation of all edges (V - 1) times
        calculateMinDistance(V, src, edges, distance);

        // Step 3: Check for negative-weight cycles with one more relaxation
        bool isDistanceUpdated = relax(src, edges, distance);
        if (isDistanceUpdated == true)
        {
            // Negative cycle detected
            return {-1};
        }

        // Step 4: Return final shortest distances
        return distance;
    }
};



// Bellman-Ford Steps Recap:
// Initialize all distances to ∞, except the source.
// Relax all edges V - 1 times.
// Check for negative cycles using one final pass.
// If a cycle is found → return {-1}.
// Otherwise → return the distance[] array.


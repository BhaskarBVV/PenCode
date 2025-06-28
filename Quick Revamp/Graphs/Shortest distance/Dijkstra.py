# https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
from typing import List


class Solution:
    INF = 9999999999

    def get_min_distance_vertex(self, distance: List, visited: List):
        min = Solution.INF
        min_vertex = -1
        for _ in range(0, len(visited)):
            if visited[_] is False and distance[_] < min:
                min = distance[_]
                min_vertex = _
        return min_vertex

    def dijkstra(self, V, adj, S):
        # adj -> for every index => List of connected vertices with weight.
        visited = [False] * V
        distance = [Solution.INF] * V
        distance[S] = 0
        while True:
            min_vertex = self.get_min_distance_vertex(distance, visited)
            if min_vertex == -1:
                break
            visited[min_vertex] = True
            for edge in adj[min_vertex]:
                if distance[edge[0]] > distance[min_vertex] + edge[1]:
                    distance[edge[0]] = distance[min_vertex] + edge[1]
        return distance
      #  This distance array represents the minimum distance to reach to each vertex from source vertex s

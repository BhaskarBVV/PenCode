from typing import List

class Solution:

    def dfs(self, vertex: int, visited: List, adj: List[List], order: List):
        for nbr in adj[vertex]:
            if visited[nbr] == False:
                self.dfs(nbr, visited, adj, order)
        visited[vertex] = True
        order.append(vertex)
    
    #Function to return list containing vertices in Topological order.
    def topoSort(self, V, adj):
        visited = [False]*V
        topological_order = []
        for vertex in range(0,V):
            if visited[vertex] == False:
                self.dfs(vertex, visited, adj, topological_order)
        topological_order.reverse()
        return topological_order




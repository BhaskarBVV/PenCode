# https://www.geeksforgeeks.org/problems/mother-vertex/1

class Solution:
    def __init__(self):
        self.visited = []
        self.adj = []

    def dfs(self, node):
        self.visited[node] = True
        for nbr in self.adj[node]:
            if not self.visited[nbr]:
                self.dfs(nbr)

    def findMotherVertex(self, V, adj):
        self.adj = adj
        self.visited = [False] * V
        last_finished = -1

        # Step 1: Find the last finished vertex
        for node in range(V):
            if not self.visited[node]:
                self.dfs(node)
                last_finished = node

        # Step 2: Verify if it's a mother vertex
        self.visited = [False] * V
        self.dfs(last_finished)

        if all(self.visited):
            return last_finished
        return -1

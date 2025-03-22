# https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

from typing import List

class Solution:

    def do_dfs(self, current_node):
        self.visited[current_node] = True
        self.dfs_ans.append(current_node)
        for nbr in self.adj[current_node]:
            if self.visited[nbr] == False:
                self.do_dfs(nbr)
    
    #Function to return a list containing the DFS traversal of the graph.
    def dfsOfGraph(self, adj):
        total_nodes = len(adj)
        self.adj:List[List[int]] = adj
        self.dfs_ans = []
        self.visited = [False] * total_nodes
        self.do_dfs(0)
        return self.dfs_ans        
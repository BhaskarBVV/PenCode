# https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

from typing import List
from queue import Queue

class Solution:
    
    def bfsOfGraph(self, adj: List[List[int]]) -> List[int]:
        self.total_nodes = len(adj)
        self.visited = [False] * self.total_nodes
        self.bfs_ans = []
        q = Queue()
        q.put(0)
        while not q.empty():
            current_node = q.get()
            if self.visited[current_node] is False:
                self.bfs_ans.append(current_node)
                self.visited[current_node] = True
                for _ in adj[current_node]:
                    if self.visited[_] == False:
                        q.put(_)
        return self.bfs_ans

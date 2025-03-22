# https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

from typing import List


class Solution:
    def printGraph(self, V : int, edges : List[List[int]]) -> List[List[int]]:
        adj_list = [[] for vertex in range(V)]
        for edge in edges:
            vertex_1 = edge[0]
            vertex_2 = edge[1]
            adj_list[vertex_1].append(vertex_2)
            adj_list[vertex_2].append(vertex_1)
        return adj_list

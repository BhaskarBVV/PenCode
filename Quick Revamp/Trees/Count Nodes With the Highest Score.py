# https://leetcode.com/problems/count-nodes-with-the-highest-score/description/

from typing import List


class Solution:

    def update_score_and_count(self, score):
        print(score)
        if self.max_score < score:
            self.max_score = score
            self.max_score_nodes = 1
        elif self.max_score == score:
            self.max_score_nodes += 1

    def travserse(self, root: int):
        if self.adj.get(root) == None:
            score = self.total_nodes-1
            self.update_score_and_count(score)
            # left child of leaf = 0, right child of leaf = 0, total childs of caller node = 0+1(self)+0
            return 1

        total_child = 0
        score = 1
        for child in self.adj[root]:
            # find the number of left and right childs.
            count = self.travserse(child)
            # if there is no left child then 0 will not be multiplied to score, similarly, for right and head node.
            # only sub-trees with non-zero number of nodes will be multiplied.
            if count != 0:
                total_child += count
                score *= count

        # Suppose if there is node whose left, child, and parent(total nodes - left - child -1(self)), all 3 are present.
        # So, the score due to left and right child is already calculated above,
        # With the below operation we update the score with remaining nodes
        if self.total_nodes-(1+total_child) != 0:
            score *= (self.total_nodes-(1+total_child))
        self.update_score_and_count(score)
        total_nodes = total_child + 1  # total nodes = left childs + right childs + self node
        return total_nodes

    def create_adjacency_list(self, parents: List[int]):
        self.adj: dict[int, List] = {}
        for node in range(len(parents)):
            if self.adj.get(parents[node]) == None:
                self.adj[parents[node]] = []
            self.adj[parents[node]].append(node)

    def countHighestScoreNodes(self, parents: List[int]) -> int:
        self.max_score = 0
        self.max_score_nodes = 0
        self.total_nodes = len(parents)

        self.create_adjacency_list(parents)

        self.travserse(0)
        return self.max_score_nodes

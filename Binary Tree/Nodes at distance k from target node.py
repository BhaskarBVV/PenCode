from typing import List, Dict
from collections import deque


class Solution:
    target_node_address = None

    def store_parent_and_find_target_node_address(
        self, root, parent_dict: Dict, target: int
    ) -> None:
        queue = deque([root])

        while queue:
            leaf = queue.popleft()
            if leaf.data == target:
                self.target_node_address = leaf

            if leaf.left != None:
                parent_dict[leaf.left] = leaf
                queue.append(leaf.left)

            if leaf.right != None:
                parent_dict[leaf.right] = leaf
                queue.append(leaf.right)

    def KDistanceNodes(self, root, target, k):
        parent_dict = {}
        self.store_parent_and_find_target_node_address(root, parent_dict, target)
        dst = -1
        queue = deque([self.target_node_address])
        visited = {}
        ans = []
        while queue and dst < k:
            dst += 1
            total_nodes_present_in_queue = len(queue)
            for _ in range(total_nodes_present_in_queue):
                node = queue.popleft()
                if dst == k:
                    ans.append(node.data)
                visited[node] = True
                if node.left is not None and visited.get(node.left) is None:
                    queue.append(node.left)
                    visited[node.left] = True
                if node.right is not None and visited.get(node.right) is None:
                    queue.append(node.right)
                    visited[node.right] = True
                if (
                    parent_dict.get(node) is not None
                    and visited.get(parent_dict[node]) is None
                ):
                    queue.append(parent_dict[node])
                    visited[parent_dict[node]] = True
            ans.sort()
        return ans

from typing import Dict
from collections import deque


class Solution:

    target_node_address = None

    def store_parent_and_find_target_node_address(self, root, parent_dict: Dict, target: int) -> None:
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
        
    def minTime(self, root,target):
        parent_dict = {}
        self.store_parent_and_find_target_node_address(root, parent_dict, target)

        queue = deque([self.target_node_address])
        time = -1
        visited = {}
        while queue:
            leafs_currently_burning = len(queue)

            for _ in range(leafs_currently_burning):

                leaf = queue.popleft()
                visited[leaf] = True      

                if leaf.left != None and visited.get(leaf.left) == None:
                    queue.append(leaf.left)
                    visited[leaf.left] = True

                if leaf.right != None and visited.get(leaf.right) == None:
                    queue.append(leaf.right)
                    visited[leaf.right] = True

                if parent_dict.get(leaf) != None and visited.get(parent_dict[leaf]) == None:
                    queue.append(parent_dict[leaf])
                    visited[parent_dict[leaf]] = True

        return time
    

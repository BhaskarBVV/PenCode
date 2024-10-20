from queue import Queue
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# using BFS, level order traversal


class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        my_queue: Queue[TreeNode] = Queue()
        min_height = 0
        my_queue.put(root)
        while (not my_queue.empty()):
            min_height += 1
            size = my_queue.qsize()
            for _ in range(size):
                top_node = my_queue.get()
                if top_node.left is None and top_node.right is None:
                    return min_height
                if top_node.left is not None:
                    my_queue.put(top_node.left)
                if top_node.right is not None:
                    my_queue.put(top_node.right)
        return min_height

# using DFS


class Solution:

    def __init__(self) -> None:
        self.min_height = 999999999

    def get_height(self, root: Optional[TreeNode], current_height: int) -> None:
        if root is None:
            return
        if root.left is None and root.right is None:
            self.min_height = min(self.min_height, current_height)
        self.get_height(root.left, current_height+1)
        self.get_height(root.right, current_height+1)

    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 1
        self.get_height(root, 1)
        return self.min_height

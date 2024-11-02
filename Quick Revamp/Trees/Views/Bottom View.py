# https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

from typing import Optional
from queue import Queue


class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


class DfsSolution:
    def traverse(self, root, index, bottom_view, height):
        # In DFS solution, height is also needed
        if root is None:
            return

        temp = bottom_view.get(index)
        if temp is not None and temp[1] <= height:
            bottom_view[index] = (root.data, height)

        height += 1
        self.traverse(root.left, index - 1, bottom_view, height)
        self.traverse(root.right, index + 1, bottom_view, height)

    def bottomView(self, root):
        bottom_view = {}
        index = 0
        self.traverse(root, index, bottom_view)
        ans = []
        for key in sorted(bottom_view.keys()):
            ans.append(bottom_view[key][0])
        return ans

# ------------------------------------ ------------------------------------ ------------------------------------


class NodeIndexInfo:
    def __init__(self, node: Node, index: int) -> None:
        self.node = node
        self.index = index


class BfsSolution:
    # via level order traversal
    def bottomView(self, root: Optional[Node]):
        _queue = Queue()
        bottom_view = {}

        _queue.put(NodeIndexInfo(root, 0))
        _items_added_to_queue = 1

        while not _queue.empty():
            _queue_size = _items_added_to_queue
            _items_added_to_queue = 0

            for _ in range(_queue_size):
                top_node: NodeIndexInfo = _queue.get()
                bottom_view[top_node.index] = top_node.node.data
                if top_node.node.left:
                    _queue.put(NodeIndexInfo(top_node.node.left, top_node.index-1))
                    _items_added_to_queue += 1
                if top_node.node.right:
                    _queue.put(NodeIndexInfo(top_node.node.right, top_node.index+1))
                    _items_added_to_queue += 1

        ans = []
        for index in sorted(bottom_view.keys()):
            ans.append(bottom_view[index])
        return ans

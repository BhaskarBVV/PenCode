# https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

from queue import Queue
from typing import Dict, List, Optional


class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


class DfsSolution:
    def traverse(self, root: Optional[Node], index: int,
                 vertical_view: Dict[int, List[int]], height: int):
        # In DFS solution, height is also needed.
        # Because the node that appear in the above level must appear before in the answer,
        # as compared to other node in same index, but in lower (Downer) level.
        if root is None:
            return

        temp = vertical_view.get(index)
        if temp is None:
            vertical_view[index] = []
        vertical_view[index].append((root.data, height))

        self.traverse(root.left, index - 1, vertical_view, height+1)
        self.traverse(root.right, index + 1, vertical_view, height+1)

    def verticalOrder(self, root):
        vertical_view: Dict[int, List[int]] = {}
        index = 0
        height = 0
        self.traverse(root, index, vertical_view, height)
        ans = []
        for index in sorted(vertical_view.keys()):
            # sorting the nodes on the basis of height, (node data, height)
            for node in sorted(vertical_view[index], key=lambda x: x[1]):
                ans.append(node[0])
        return ans


# -----------------------------------------------------------------------------------------------------


class NodeIndexInfo:
    def __init__(self, node: Node, index: int) -> None:
        self.node = node
        self.index = index


class BfsSolution:

    @staticmethod
    def update_view(view: Dict[int, List[int]], node: Node, index: int):
        if view.get(index) is None:
            view[index] = []
        view[index].append(node.data)

    # Function to find the vertical order traversal of Binary Tree.
    def verticalOrder(self, root):
        _queue = Queue()
        veritcal_view: dict[int, list[int]] = {}

        _queue.put(NodeIndexInfo(root, 0))
        _items_added_to_queue = 1

        while not _queue.empty():
            _queue_size = _items_added_to_queue
            _items_added_to_queue = 0

            for _ in range(_queue_size):
                top_node: NodeIndexInfo = _queue.get()
                BfsSolution.update_view(
                    veritcal_view, top_node.node, top_node.index)

                if top_node.node.left:
                    _queue.put(NodeIndexInfo(
                        top_node.node.left, top_node.index-1))
                    _items_added_to_queue += 1

                if top_node.node.right:
                    _queue.put(NodeIndexInfo(
                        top_node.node.right, top_node.index+1))
                    _items_added_to_queue += 1

        ans = []
        for index in sorted(veritcal_view.keys()):
            for node in veritcal_view[index]:
                ans.append(node)
        return ans

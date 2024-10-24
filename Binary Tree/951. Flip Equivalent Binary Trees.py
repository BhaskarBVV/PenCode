# https://leetcode.com/problems/flip-equivalent-binary-trees/description/

# For both nodes (node 1 of A Tree, and node 2 of B Tree) traverse
# left left, right right,
# and left right, right left.
# if the AND of either of them is true, the current nodes will be identical.

class Solution:

    def checkFlip(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if (root1 is None and root2 is not None) or (root1 is not None and root2 is None):
            return False
        if root1 and root2 and root1.val != root2.val:
            return False
        if root1 is None and root2 is None:
            return True

        a1 = self.checkFlip(root1.left, root2.right)
        b1 = self.checkFlip(root1.right, root2.left)

        a2 = self.checkFlip(root1.left, root2.left)
        b2 = self.checkFlip(root1.right, root2.right)

        return (a1 and b1) or (a2 and b2)

    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        return self.checkFlip(root1, root2)

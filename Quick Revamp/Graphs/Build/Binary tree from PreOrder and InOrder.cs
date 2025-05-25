https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

public class Solution {
    private TreeNode BuildTreeHelper(int[] preOrder, int[] inOrder, int inOrderStart, int inOrderEnd, int preOrderStart, int preOrderEnd, Dictionary<int,int> inOrderDict)
    {
        if(inOrderStart>inOrderEnd || preOrderStart>preOrderEnd)
        {
            return null;
        }
        var rootNodeValue = preOrder[preOrderStart];
        var root = new TreeNode(rootNodeValue);

        var rootNodeIndexInInOrder = inOrderDict[rootNodeValue];
        
        int leftInOrderStart = inOrderStart,
        leftInOrderEnd = rootNodeIndexInInOrder-1,
        rightInOrderStart = rootNodeIndexInInOrder+1,
        rightInOrderEnd = inOrderEnd;

        int leftPreOrderStart = preOrderStart+1,
        leftPreOrderEnd = leftPreOrderStart+(leftInOrderEnd-leftInOrderStart),
        rightPreOrderStart = leftPreOrderEnd+1,
        rightPreOrderEnd = preOrderEnd;

        root.left = BuildTreeHelper(preOrder, inOrder, leftInOrderStart, leftInOrderEnd, leftPreOrderStart, leftPreOrderEnd, inOrderDict);
        root.right = BuildTreeHelper(preOrder, inOrder, rightInOrderStart, rightInOrderEnd, rightPreOrderStart, rightPreOrderEnd, inOrderDict);
        
        return root;
    }
    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        var inOrderDict = new Dictionary<int,int>();
        for(int i=0; i<inorder.Length; i++){
            inOrderDict[inorder[i]]=i;
        }
        return BuildTreeHelper(preorder, inorder, 0, preorder.Length-1, 0, inorder.Length-1, inOrderDict);
    }
}

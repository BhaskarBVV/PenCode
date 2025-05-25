// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

public class Solution {
    private TreeNode BuildTreeHelper(int[] inorder, int[] postorder, Dictionary<int,int> inorderDict, 
    int inorderStart, int inorderEnd, int postorderStart, int postorderEnd){
        
        if(inorderStart>inorderEnd || postorderStart>postorderEnd){
            return null;
        }

        int rootNodeValue = postorder[postorderEnd];
        int rootNodeIndexInInorder = inorderDict[rootNodeValue];
        // Console.WriteLine($"The root {rootNodeValue} is in inorder at index {rootNodeIndexInInorder}");

        int leftInorderStart = inorderStart,
        leftInorderEnd = rootNodeIndexInInorder-1,
        rightInorderStart = rootNodeIndexInInorder+1,
        rightInorderEnd = inorderEnd;
        // Console.WriteLine($"Inorder: {leftInorderStart},{leftInorderEnd},{rightInorderStart},{rightInorderEnd}");

        int rightPostorderEnd = postorderEnd-1,
        rightPostorderStart = rightPostorderEnd-(rightInorderEnd-rightInorderStart),
        leftPostorderEnd = rightPostorderStart-1,
        leftPostorderStart = postorderStart;
        // Console.WriteLine($"Postorder: {leftPostorderStart},{leftPostorderEnd},{rightPostorderStart},{rightPostorderEnd}");

        var root = new TreeNode(rootNodeValue);
        root.left = BuildTreeHelper(inorder, postorder, inorderDict, leftInorderStart, leftInorderEnd,
        leftPostorderStart, leftPostorderEnd);
        root.right = BuildTreeHelper(inorder, postorder, inorderDict, rightInorderStart, rightInorderEnd,
        rightPostorderStart, rightPostorderEnd);

        return root;
    }

    public TreeNode BuildTree(int[] inorder, int[] postorder) {
        var inorderDict = new Dictionary<int,int>();
        for(int i=0; i<inorder.Length; i++){
            inorderDict[inorder[i]]=i;
        }
        var numberOfNodes = inorder.Length;
        return BuildTreeHelper(inorder, postorder, inorderDict, 0, numberOfNodes-1, 0, numberOfNodes-1);
    }
}

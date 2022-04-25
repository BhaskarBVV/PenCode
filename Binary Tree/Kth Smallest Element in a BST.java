class Solution {
    int item_no, value;

    public void inorder(TreeNode root, int k) {
        if (root == null)
            return;
        inorder(root.left, k);
        item_no += 1;
        if (item_no == k)
            value = root.val;
        inorder(root.right, k);
    }

    public int kthSmallest(TreeNode root, int k) {
        item_no = 0;
        value = -1;
        inorder(root, k);
        return value;
    }
}

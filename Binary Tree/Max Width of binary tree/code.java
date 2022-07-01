import java.util.*;

class JavaEditor2 {
  
    //------------------------------------
    public class TreeNode 
    {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) 
        {
            this.val = val;
        }
    }

    //------------------------------------
    class pair 
    {
        long min, max;
    }

    //------------------------------------
    class Solution 
    {

        long ans = 0;
        HashMap<Integer, pair> hm = new HashMap<>();

        public void helper(TreeNode root, int lvl, long idx) {
            if (root == null)
                return;

            helper(root.left, lvl + 1, 2 * idx);
            helper(root.right, lvl + 1, 2 * idx + 1);

            if (hm.containsKey(lvl)) {
                hm.get(lvl).max = idx;
            } else {
                pair temp = new pair();
                temp.max = idx;
                temp.min = idx;
                hm.put(lvl, temp);
            }
            long width = hm.get(lvl).max - hm.get(lvl).min + 1;
            if (width > ans)
                ans = width;
        }

        public int widthOfBinaryTree(TreeNode root) {
            long idx = 0;
            helper(root, 1, idx);
            return (int) ans;
        }
    }
}

// using postorder traversal;
// similar to the diameter of tree.
// we'll return max value from (left, right childs) + currrent root value.

// and for comparison we'll compare leftSum, rightSum, leftSum+rightSum+currentRootValue.

// for the above comparison the following code can easily work
// int left_val = max(0, left);
// int right_val = max(0, right);
// ans = max(ans, left_val + right_val + root->val);

class Solution
{
public:
    int treeHelper(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return INT_MIN;
        int left = treeHelper(root->left, ans);
        int right = treeHelper(root->right, ans);

        int left_val = max(0, left);
        int right_val = max(0, right);

        ans = max(ans, left_val + right_val + root->val);
        return max(left_val, right_val) + root->val;
    }
    int maxPathSum(TreeNode *root)
    {
        int max_ans = INT_MIN;
        treeHelper(root, max_ans);
        return max_ans;
    }
};

https://leetcode.com/problems/binary-tree-maximum-path-sum/

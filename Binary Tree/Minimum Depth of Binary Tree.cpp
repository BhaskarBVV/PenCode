// https://leetcode.com/problems/minimum-depth-of-binary-tree/

class Solution
{
public:
    void treeHelper(TreeNode *root, int &ans, int curH)
    {
        if(root==NULL)
            return;
        if (root->left == NULL & root->right == NULL)
        {
            ans = min(ans, curH);
            return;
        }
        treeHelper(root->left, ans, curH + 1);
        treeHelper(root->right, ans, curH + 1);
    }
    int minDepth(TreeNode *root)
    {
        if (root==NULL)
            return 0;
        int ans = INT_MAX;
        treeHelper(root, ans, 1);
        return ans;
    }
};

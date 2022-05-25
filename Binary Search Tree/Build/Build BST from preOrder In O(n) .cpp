// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution
{
public:
    int i;
    TreeNode *build(vector<int> &preorder, int mn, int mx)
    {
        if (i >= preorder.size())
            return NULL;
        
        if (preorder[i] <= mn || preorder[i] >= mx)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[i]);
        
        i++;
        
        root->left = build(preorder, mn, root->val);
        root->right = build(preorder, root->val, mx);
        
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = NULL;
        i = 0;
        root = build(preorder, INT_MIN, INT_MAX);
        return root;
    }
};

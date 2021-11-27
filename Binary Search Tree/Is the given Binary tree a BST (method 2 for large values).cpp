/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool is_BST(TreeNode *root, long long int min, long long int max)
    {
        if (root == NULL)
            return true;
        bool x= is_BST(root->left, min, root->val);
        bool y= is_BST(root->right, root->val, max);
        bool z=((root->val > min && root->val < max) ? true : false);
        return x&&y&&z;
    }
    bool isValidBST(TreeNode* root) 
    {
        return is_BST(root,LLONG_MIN,LLONG_MAX);
    }
};

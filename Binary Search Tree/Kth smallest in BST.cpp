class Solution {
public:
    int loop=0, x;
    void inorder(TreeNode* root, int k)
    {
        if(root==NULL)
            return;
        inorder(root->left,k);
        loop++;
        if(loop==k)
            x= root->val;
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
         inorder(root, k);
        return x;
    }
};

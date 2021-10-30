class Solution {
public:
    bool treeHelper(TreeNode* root, int k ,set<int> &s)
    {
        if(root==NULL)
            return false;
        if(s.find(k-root->val)!=s.end())
            return true;
        s.insert(root->val);
        return treeHelper(root->left,k,s) || treeHelper(root->right,k,s);
    }
    bool findTarget(TreeNode* root, int k) 
    {
        set<int>s;
        return treeHelper(root, k , s);
    }
};

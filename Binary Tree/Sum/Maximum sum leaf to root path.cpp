class Solution{
    public:
    void treeHelper(Node*root, int &ans, int sum)
    {
        if(root==NULL)
        return;
        sum+=root->data;
        if(root->left==NULL && root->right==NULL)
        {
            ans=max(ans,sum);
            return;
        }
        treeHelper(root->left,ans, sum);
        treeHelper(root->right,ans, sum);
    }
    int maxPathSum(Node* root)
    {
        int ans=INT_MIN;
        treeHelper(root, ans,0);
        return ans;
    }
};

https://practice.geeksforgeeks.org/problems/maximum-sum-leaf-to-root-path/1/#

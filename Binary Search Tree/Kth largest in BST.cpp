// right root left

class Solution
{
    public:
    void treeHelper(Node*root, int &k, int &x)
    {
        if(root==NULL)
        {
            return;
        }
        treeHelper(root->right,k,x);
        k-=1;
        if(k==0)
        x=root->data;
        treeHelper(root->left,k,x);
        
    }
    int kthLargest(Node *root, int k)
    {
        int x;
        treeHelper(root,k,x);
        return x;
    }
};

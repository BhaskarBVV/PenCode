class Solution{
    public:
    // Return the size of the largest sub-tree which is also a BST
    class pair
    {
        public:
        int mn,mx,size;
        pair()
        {
            mn=0; mx=0; size=0;
        }
    };
  
  // bottom up approach
  // Check for left first and then for right;
  // for leaf node return MAX values
  // use post order travesral.
    pair treeHelper(Node* root)
    {
        pair p;
        if(root==NULL)
        {
            p.mn=INT_MAX;
            p.mx=INT_MIN;
            p.size=0;
            return p;
        }
        pair left=treeHelper(root->left);
        pair right=treeHelper(root->right);
        if(root->data > left.mx && root->data < right.mn)
        {
            p.mx=max(right.mx,root->data);
            p.mn=min(left.mn,root->data);
            p.size=left.size+right.size+1;
            return p;
        }
            p.mx=INT_MAX;
            p.mn=INT_MIN;
            p.size=max(left.size,right.size);
        return p;
    }
    int largestBst(Node *root)
    {
    	pair p=treeHelper(root);
    	return p.size;
    }
};

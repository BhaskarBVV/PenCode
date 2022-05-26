// https://practice.geeksforgeeks.org/problems/image-multiplication0627/1

class Solution
{
    public:
    void treeHelper(Node* a, Node* b, long long int &ans)
    {
        if(a==NULL ||b==NULL)
        return;
        long long int temp=(a->data * b->data)%(1000000007);
        ans=(ans+temp)%(1000000007);
        treeHelper(a->left, b->right, ans);
        treeHelper(a->right, b->left, ans);
    }
    long long imgMultiply(Node *root)
    {
        long long int ans=1;
        ans=(root->data * root->data)%(1000000007);
        treeHelper(root->left, root->right, ans);
        return ans;
    }
};

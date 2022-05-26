class Solution
{
public:
    void helper(Node *root, int &mn_dif, int &k)
    {
        if (root = NULL)
            return;
            
        mn_dif = min(mn_dif, abs(root->data - k));
        
        if (root->data > k)
            helper(root->left, mn_dif, k);
        else if (root->data < k)
            helper(root->right, mn_dif, k);
        else
            return;
            
    }
    int minDiff(Node *root, int K)
    {
        int mn_dif = INT_MAX;
        helper(root, mn_dif, K);
        return mn_dif;
    }
};

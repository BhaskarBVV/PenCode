class info
{
    public:
    int maxi;
    int mini; 
    int size;
    bool is_valid;
};
class Solution
{
public:
    info helper(Node *root, int &mx)
    {
        if (root == NULL)
        {
            info temp;
            temp.maxi=INT_MIN;
            temp.mini=INT_MAX;
            temp.size=0;
            temp.is_valid=true;
            return temp;
        }
        
        info left = helper(root->left, mx);
        info right = helper(root->right, mx);

        info curNode;
        curNode.size = left.size + right.size + 1;
        curNode.mini = min(root->data, left.mini);
        curNode.maxi = max(root->data, right.maxi);
        
        if (left.is_valid && right.is_valid && root->data > left.maxi && root->data < right.mini)
            curNode.is_valid = true;
        else
            curNode.is_valid = false;

        if (curNode.is_valid)
            mx = max(mx, curNode.size);
            
        return curNode;
    }
    int largestBst(Node *root)
    {
        int mx = 0;
        info ans = helper(root, mx);
        return mx;
    }
};

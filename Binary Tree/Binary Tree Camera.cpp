class Solution
{
public:
    int tot=0;
    int Camera = 0, Monitored = 1, NotMonitored = 2;
    
    int minCameraCover(TreeNode *root)
    {
        int ans = helper(root);
        
        if (ans == NotMonitored) // jab root hi not-monitored hai tab kya krenge, uske liye camera lagaenge and tot ko  increase krenge.
            tot += 1;
        
        return tot;
    }
    int helper(TreeNode *root)
    {
        if (root == NULL)
            return Monitored;
        
        int left = helper(root->left);
        int right = helper(root->right);
        
        if (left == NotMonitored || right == NotMonitored)
        {
            tot++;
            return Camera;
        }
        else if (left == Camera || right == Camera)
        {
            return Monitored;
        }
        else
        {
            return NotMonitored;
        }
    }
};

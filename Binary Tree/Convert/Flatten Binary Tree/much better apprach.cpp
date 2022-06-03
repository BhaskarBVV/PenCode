//Just travel in the order in which quesiton asks and push the address of nodes in the stack
//now join the nodes, until the stack gets empty (grow the list in rev order)
class Solution {
public:
    void helper(stack<TreeNode*>&s, TreeNode *root)
    {
        if(root==NULL) return;
        
        s.push(root);
        helper(s,root->left);
        helper(s,root->right);
    }
    void flatten(TreeNode* root) {
        
        if(root==NULL) return;
        stack<TreeNode*>s;
        
        helper(s,root);
        
        TreeNode *ans=NULL,*temp=ans;
        
        while(s.size()>0)
        {
            temp=s.top();
            s.pop();
            
            temp->left=NULL;
            temp->right=ans;
            
            ans=temp;
        }
    }
};

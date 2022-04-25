int find(TreeNode* root, int x, int &parent, int l)
    {
        if(root==NULL)
            return 0;
        if(root->val==x)
            return l;
  
        parent=root->val;
        int left_l=find(root->left,x,parent,l+1);
        if(left_l)
            return left_l;
  
        parent=root->val;
        int right_l=find(root->right,x,parent,l+1);
        if(right_l)
            return right_l;
  
        return 0;
    }

// update parent for each function call, if value found return its level
// if parent of both values are diff and level of both values are same then return true,

    bool isCousins(TreeNode* root, int x, int y) 
    {
        int fparent=-1;
        int f_level=find(root,x,fparent,0);
        
        int sparent=-1;
        int s_level=find(root,y,sparent,0);
        
        // cout<<fparent<<" "<<sparent<<endl;
        
        if(fparent!=sparent && f_level == s_level)
            return true;
      
        return false;
    }

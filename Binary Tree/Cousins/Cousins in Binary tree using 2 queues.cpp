bool isCousins(TreeNode* root, int x, int y) 
    {
        queue<int>val_qu;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        val_qu.push(root->val);
        int a;
        TreeNode* temp=NULL;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
          // if temp==NULL means that we have all nodes of a particular level.
          // traverse the value queue if one value is found than empty the queue until childs of one that parent are removed.
          // Now, traverse the same queue until second value is found, if found until queue is empty return true
          // if value queue gets empty and second child within that level is not found return false.
            if(temp==NULL)
            {
                while(!val_qu.empty())
                {
                    a=val_qu.front();
                    val_qu.pop();
                    if(a==x || a==y)
                    {
                        while(val_qu.front()!=-1)
                        {
                            val_qu.pop();
                        }
                        val_qu.pop();
                        while(!val_qu.empty())
                        {
                            if(val_qu.front()==x || val_qu.front()==y)
                            return true;
                            val_qu.pop();
                        }
                        return false;
                    }
                }
                if(!q.empty())
                    q.push(NULL);   
            }
            else
            {
                if(temp->left)
                {q.push(temp->left);val_qu.push(temp->left->val);}
                if(temp->right)
                {q.push(temp->right);val_qu.push(temp->right->val);}
                val_qu.push(-1);// Nodes of evey parent are saperated by -1;
            }
        }
        return false;
    }

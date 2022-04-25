class Codec {
public:

    string serialize(TreeNode* root) 
    {
        if (root == NULL)
        return "";
    queue<TreeNode *> q;
    q.push(root);
    string v="";
    TreeNode *temp = NULL;
        string x;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            v+="#,";
        }
        else
        {
            int num =temp->val;
            ostringstream str1;
            str1 << num;
            x = str1.str();//converted to string
            v+=x;//strings cannot be pushed back.
            v.push_back(',');//characters can be pushed back.
            if (temp->left)
                q.push(temp->left);
            else
                q.push(NULL);
            if (temp->right)
                q.push(temp->right);
            else
                q.push(NULL);
        }
    }
        // cout<<v<<endl;
        // serialized the tree into string, where every number is separated by "#";
    return v;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s)
    {
        //This string is converted to vector.
        // Bcz in string we don't know how the starting index of number and also due to the 
        // presence of "#" the index are difficult to predict.
        if(s=="")
            return NULL;
        vector<int>v;
        string x="";
        for(auto it: s)
        {
            if(it==',')
            {
                stringstream geek(x);
                int num = 0;
                geek >> num;
                v.push_back(num);
                x="";
            }
            else if(it=='#')
                // we cannot take -1 to point NULL value, because there are -1 values also present as node value, 
                //hence we take that value to point NULL which are not in range of values of TREE, here the was only -1000 <= Node.val <= 1000
            x+="-10000";
            else
            x+=it;
        }
        // for(auto it: v)
        //     cout<<it<<" ";
        TreeNode* root=new TreeNode(v[0]);
        queue<TreeNode*>q;
        q.push(root);
        int i=0;
        TreeNode* temp=NULL;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(i*2+1<v.size())
            {
                if(v[i*2+1]!=-10000)
                {
                    TreeNode* l= new TreeNode (v[2*i+1]);
                    temp->left=l;
                    q.push(l);
                }
                else
                temp->left=NULL;
            }
            if(i*2+2<v.size())
            {
                if(v[2*i+2]!=-10000)
                {
                    TreeNode* r= new TreeNode(v[2*i+2]);
                    temp->right=r;
                    q.push(r);
                }
                else
                    temp->right=NULL;
            }
            i++;
        }
        return root;
    }
};

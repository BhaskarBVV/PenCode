The inorder traversal of BST is always sorted, heance we can use current val, cout, max_cnt to find modes.

class Solution {
public:
    int cnt=0, mx_cnt=0, cur_val;
    vector<int>r;
    void count_node(TreeNode* root)
    {
        if(root->val!=cur_val)
        {
            cur_val=root->val;
            cnt = 1;
        }
        else
        {
            cnt++;
        }
        if(cnt>mx_cnt)
            {
                mx_cnt=cnt;
                r.clear();
                r.push_back(root->val);
            }
            else if(cnt==mx_cnt)
            {
                r.push_back(root->val);
            }
    }
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        count_node(root);
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) 
    {
        inorder(root);
        return r;
    }
};

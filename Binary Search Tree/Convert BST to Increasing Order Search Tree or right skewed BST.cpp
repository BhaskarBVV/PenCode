// 1. Using vector and then forming new BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v)
    {
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* increasingBST(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        TreeNode*roota=new TreeNode(-1);
        TreeNode*dummy=roota;
        vector<int>v;
        inorder(root,v);
        for(auto it: v)
        {
            TreeNode * temp= new TreeNode(it);
            roota->left=NULL;
            roota->right=temp;
            roota=temp;
        }
        return dummy->right;
    }
};



// 2. Changing the links in the given BST.

class Solution {
public:
    void inorder(TreeNode* root, TreeNode* &temp)
    {
        if(root==NULL)
            return;
        inorder(root->left, temp);
        temp->right=root;
        root->left=NULL;
        temp=root; 
        inorder(root->right,temp);
    }
    TreeNode* increasingBST(TreeNode* root) 
    {
        TreeNode* new_root=new TreeNode(-1);
        TreeNode* temp=new_root;
        inorder(root,temp);
        return new_root->right;
    }
};

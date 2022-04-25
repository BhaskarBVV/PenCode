//                      Root           
//                        3
//                     /     \          
//                   4        5      ex-> let suppose the node with value 4 is grandParent with even value then its child are pushed in vector <1,2>
//                  / \      / \          Now the sum of child of <1,2> are calculated ->> child of 1(8,9) + child of 2(0) = 8+9+0=17.
//                 1   2    7   9           
//                / \   \      / \
//               8  9    0    10  12



class Solution {
public:
    //Pushed the child(Parents) of even valued nodes(grand Parents) in vector grandP, and sum is calculated from the child(children) of nodes (parent) stored in vector
    void inorder(TreeNode* root, vector<TreeNode*>&grandP)
    {
        if(root==NULL)
            return;
        inorder(root->left,grandP);
        if(root->val%2==0)
        {
            if(root->left)
                grandP.push_back(root->left);
            if(root->right)
                grandP.push_back(root->right);
        }
        inorder(root->right,grandP);
    }
    int sumEvenGrandparent(TreeNode* root) 
    {
        vector<TreeNode*>grandP;
        inorder(root,grandP);
        int sum=0;
        for(auto it: grandP)
        {
            if(it->left)
                sum+=it->left->val;
            if(it->right)
                sum+=it->right->val;
        }
        return sum;
    }
};

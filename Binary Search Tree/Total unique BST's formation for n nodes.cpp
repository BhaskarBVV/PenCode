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
    vector<TreeNode*> treeHelper(int s, int e)
    {
        if(s>e)
            return {NULL};
        vector<TreeNode*>v;
        for(int i=s;i<=e;i++)
        {
          // for every value selected from start to end, find the (values and) the trees that will lie in the left side and right side of selected node {start,end}
            vector<TreeNode*>left=treeHelper(s,i-1); // creates the trees for the remaining values that are at the left of selected value
            vector<TreeNode*>right=treeHelper(i+1,e); // creates the trees for the remaining values that are at the right of selected value
            for(auto l: left)
            {
              // since, each left sub-tree formed can combine with each right sub-tree formed, hence start a nested loop over them.
                for(auto r: right)
                {
                  // At every combination make the selected value (from the above for loop for(int i=s;i<=e;i++)) as root.
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    v.push_back(root);//push that root in vector, this vector can be the left subtree vector or right subtree or main tree vector of calling function 
                  // and return it after all the combinations have been made.
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) 
    {
      // the root node can be any value from 1 to n , hence start =1 and end=n passsed in helper function.
        vector<TreeNode*>v=treeHelper(1,n);
        return v;
    }
};

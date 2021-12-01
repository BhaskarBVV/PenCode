//                         1                       1                     1
//                        / \                     / \                     \
//                       2   3    ->>            2   3     -->>            3            tarhet to be deleted =2
//                      /   / \                       \                     \
//                     2   2   4                       4                     4
                      
// Input: root = [1,2,3,2,null,2,4], target = 2
// Output: [1,null,3,null,4]
// Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
// After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
  
// Input: root = [1,3,3,3,2], target = 3
// Output: [1,3,null,null,2]



class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        if(root==NULL)
            return NULL;
        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);
        if(root->left==NULL && root->right==NULL && root->val==target)
            return NULL;
        return root;
    }
};

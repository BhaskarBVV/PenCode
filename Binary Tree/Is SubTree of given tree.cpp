//                    Root           
//                     3
//                    / \           SubRoot
//                   4   5            4
//                  / \              / \ 
//                 1   2            1   2
//             The subTree must be complete till end in main Tree.
                     
//                      Root           
//                        3
//                     /    \           SubRoot
//                   4       5            4
//                  / \     /            / \ 
//                 1   2   7            1   2     
//                / \   \
//               8  9    0              Here this SubRoot is not the subTree of the given tree, bcz it is not present till end.

// Input: root = [3,4,5,1,2], subRoot = [4,1,2]
// Output: true
  
// Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
// Output: false


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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root==NULL && subRoot==NULL)
            return true;
        if(root==NULL && subRoot!=NULL)
            return false;
        if(root!=NULL && subRoot==NULL)
            return false;
        if(isEqual(root,subRoot))
        {
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    bool isEqual(TreeNode* root,TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL)
            return true;
        if(root==NULL || subRoot==NULL)
            return false;
        if(root->val!=subRoot->val){
            return false;
        }
        return isEqual(root->left,subRoot->left) && isEqual(root->right,subRoot->right);
    }
};

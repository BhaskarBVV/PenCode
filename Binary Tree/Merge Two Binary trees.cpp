// Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
// Output: [3,4,5,5,4,null,7]

// Input: root1 = [1], root2 = [1,2]
// Output: [2,2]

//           1            2                    3
//          / \          / \                  / \
//        3    2   +    1   3     =>         4   5
//       /               \   \              / \   \
//      5                 4   7            5   4   7
                   

            
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==NULL && root2==NULL)
            return NULL;
        if(root1 && !root2)
            return root1;
        else if(root2 && !root1)
            return root2;
        root1->val=root1->val + root2->val;
        root1->left=mergeTrees(root1->left,root2->left);
        root1->right=mergeTrees(root1->right,root2->right);
        return root1;
    }
};

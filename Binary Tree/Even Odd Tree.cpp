// A binary tree is named Even-Odd if it meets the following conditions:

// The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
// For every even-indexed level, all nodes at this level should have odd integer values "in strictly increasing order (from left to right)".
// For every odd-indexed level, all nodes at this level should have even integer values "in strictly decreasing order (from left to right)".


//                                     1    ---->Increasing value, level=0    even level, odd values 
//                                   /   \
//                                 10     4  ---->Decreasing value, level=1    odd level, even values
//                                /      / \
//                               3      7   9 ---->Increasing value, level=2
//                              / \    /     \
//                             12  8  6       2 ---->Decreasing value, level=3

// Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
// Output: true
// Explanation: The node values on each level are:
// Level 0: [1]
// Level 1: [10,4]
// Level 2: [3,7,9]
// Level 3: [12,8,6,2]
// Since levels 0 and 2 are all odd and increasing, and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
  
// Input: root = [5,4,2,3,3,7]
// Output: false
// Explanation: The node values on each level are:
// Level 0: [5]
// Level 1: [4,2]
// Level 2: [3,3,7]
// Node values in the level 2 must be in strictly increasing order, so the tree is not Even-Odd.





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
    bool isEvenOddTree(TreeNode* root) 
    {
        int x=0, pre=INT_MIN;
      // The first level = 0 and its values must be in increasing order, so pre-value for it in beginning must have minimum value.
        if(root==NULL)
            return true;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        TreeNode* temp=NULL;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                x++;
              // Here we will increment the level value(x) 
              // and also set the pre_value for new level
              // if next new level is odd then its values must be Decreasing hence set pre_value to INT_MAX.
              // if next new level is even then its values must be Increasing hence set pre_value to INT_MIN.
                if(x%2==0)
                {
                    pre=-1;
                }
                else
                {
                    pre=INT_MAX;
                }
                if(!q.empty())
                    q.push(NULL);
                
            }
            else
            {
                cout<<temp->val<<" "<<x<<endl;
                if(x%2==(temp->val)%2)// level must be odd and values must be even, vice versa. If not return false.
                    return false;
                if(x%2==0)
                {
                    // even level must have increasing value.
                    if(temp->val<=pre)  // duplicate is also not allowed bcz striclty increasing
                        return false;
                }
                else 
                {
                    // even level must have decreasing value.
                    if(temp->val >= pre)  // duplicate is also not allowed bcz striclty dereasing                                                  
                        return false;
                }
                pre=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return true;
    }
};

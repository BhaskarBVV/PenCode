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
    vector<int> rightSideView(TreeNode* root) 
    {
        if (root == NULL)
            return {};
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        TreeNode *temp;
        ans.push_back(root->val);
        int flag = 0;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                flag = 1;
                if (!q.empty())
                    q.push(NULL);
            }
            else
            {
                if (flag == 1)
                {
                    ans.push_back(temp->val);
                    flag = 0;
                }
              // Don't change the order.
                if (temp->right)
                    q.push(temp->right);
                if (temp->left)
                    q.push(temp->left);
            }
        }
        return ans;
    }
};

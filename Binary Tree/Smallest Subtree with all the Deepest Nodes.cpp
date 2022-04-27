class Solution {
public:
    TreeNode *lca(TreeNode *root, TreeNode *a, TreeNode *b)
    {
        if (root == NULL)
            return NULL;
        if (root == a)
            return a;
        if (root == b)
            return b;
        TreeNode *l = lca(root->left, a, b);
        TreeNode *r = lca(root->right, a, b);
        if (l != NULL && r != NULL)
            return root;
        if (l)
            return l;
        return r;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        queue<TreeNode *> q;
        vector<TreeNode *> last_level;
        q.push(root);
        TreeNode *temp;
        while (!q.empty())
        {
            int size = q.size();
            last_level.clear();
            while (size--)
            {
                temp = q.front();
                q.pop();
                last_level.push_back(temp);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
		// deepest nodes will be at last level
		// and the smallest subtree wil be formed at the LCA of all the nodes at last level.
		// LCA of all nodes at last level = LCA of (1st and last node) of last level.
		// 1st node and last node can be same if last level have only one node.
        return lca(root, last_level[0], *last_level.rbegin());
    }
};

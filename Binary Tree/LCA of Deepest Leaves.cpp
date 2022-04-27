class Solution
{
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
    TreeNode *lcaDeepestLeaves(TreeNode *root)
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
        if (last_level.size() == 1)
            return last_level[0];
        return lca(root, last_level[0], *last_level.rbegin());
    }
};

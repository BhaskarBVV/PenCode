https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

class Solution
{
public:
    int i;
    TreeNode *helper(string s, int lvl)
    {
        string temp = "";
        int cnt = 0;
        while (i < s.size() && s[i] == '-')
        {
            temp += '-';
            cnt++;
            i++;
        }

        // if number of "-" are equal to level, then it means that we are correct level and coming number is the correct child
        if (temp.size() == lvl)
        {
            temp = "";
            while (i < s.size() && isdigit(s[i]))
            {
                temp += s[i];
                i++;
            }
            
            TreeNode *root = new TreeNode(stoi(temp));
            root->left = helper(s, lvl + 1);
            root->right = helper(s, lvl + 1);
            return root;
        }
        // if we are not at correct level, than we have to move back (i), because we have processed the (-) in wrong level.
        i -= cnt;
        return NULL;
    }
    TreeNode *recoverFromPreorder(string s)
    {
        i = 0;
        string temp = "";
        while (i < s.size() && isdigit(s[i]))
        {
            temp += s[i];
            i++;
        }
        //Extracted the first value, and then formed its left and right tree.
        TreeNode *root = new TreeNode(stoi(temp));
		// next coming number should be at level 1  
		// don't say why only level 1, not more than 1.
		// Its 1 bcz, its preorder traversal, and without going to level 1 (either to left child or right child, root at level 0)
		// how can yout go to higher level.
        root->left = helper(s, 1);
        root->right = helper(s, 1);

        return root;
    }
};

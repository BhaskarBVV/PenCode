class Solution
{
public:
    int distributeCoins(TreeNode *root)
    {
        int moves = 0;
        helper(root, moves);
        return moves;
    }
    // pair<Node,coins>
    pair<int, int> helper(TreeNode *root, int &moves)
    {
        if (root == NULL)
            return {0, 0};
        pair<int, int> L = helper(root->left, moves);
        pair<int, int> R = helper(root->right, moves);

        pair<int, int> cur;
        // When ever there is the difference between the total nodes and the total coins at particualr node
        // (more particularly in the subtree of that node)
        // add the difference to tha ans, bcz this is equal to the amount of coins that will be moved.

        cur.first = L.first + R.first + 1;            // nodes in left subtree + in right Subtree + current Node.
        cur.second = L.second + R.second + root->val; // Coins in left subtree + Coins in right Subtree + Coins in current Node.

        moves += abs(cur.first - cur.second);

        return cur;
    }
};

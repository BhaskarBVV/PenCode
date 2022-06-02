// The list will grow from the tail.
// Traverse in Post Order and attach the nodes to form the list in  preOrder
// similarly, traverse in Pre Order and attach the nodes to from the list in PostOrder.
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *head = NULL;
        helper(root, head);
        root = head;
    }
    void helper(TreeNode *root, TreeNode *&head)
    {
        if (root == NULL)
            return;
        helper(root->right, head);
        helper(root->left, head);
        root->right = head;
        head = root;
        head->left = NULL;
    }
};

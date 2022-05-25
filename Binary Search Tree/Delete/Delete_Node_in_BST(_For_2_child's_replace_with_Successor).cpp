#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode *insert(int d, TreeNode *root)
{
    if (root == NULL)
        return new TreeNode(d);
    else if (root->val == d)
        return root;
    else if (root->val < d)
        root->right = insert(d, root->right);
    else if (root->val > d)
        root->left = insert(d, root->left);
    return root;
}
TreeNode *BuildTree()
{
    TreeNode *root = NULL;
    int d, x;
    cout << "Enter the number of nodes : ";
    cin >> d;
    for (int i = 0; i < d; i++)
    {
        cin >> x;
        root = insert(x, root);
    }
    return root;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}
int min_val(TreeNode *root)
{
    if (root->left == NULL)
        return root->val;
    return min_val(root->left);
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->val < key)
        root->right = deleteNode(root->right, key);
    else if (root->val > key)
        root->left = deleteNode(root->left, key);
    else
    {
        if (root->left == nullptr && root->right == nullptr)
            return NULL;

        else if (root->right != nullptr && root->left != nullptr)
        {
            //here, the node will be replaced by the leftmost value (or minimum value) of right subtree of the node that is to be deleted.
            int mn = min_val(root->right);
            root->val = mn;
            root->right = deleteNode(root->right, mn);
            return root;
        }
        else
        {
            if (root->right != nullptr)
                return root->right;
            else if (root->left != nullptr)
                return root->left;
        }
    }
    return root;
}
int main()
{
    TreeNode *root = BuildTree();
    int x;
    cout << "The inorder of Tree is : ";
    print(root);
    cout << "\nEnter the value to be deleted : ";
    cin >> x;
    root = deleteNode(root, x);
    //Root value must be updated,
    cout << "\nThe inorder of tree is : ";
    print(root);
}

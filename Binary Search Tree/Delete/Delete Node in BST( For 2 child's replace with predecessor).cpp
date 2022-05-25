#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    while (d != -1)
    {
        root = insert(d, root);
        cout << "Enter another Value to be entered : ";
        cin >> d;
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
int max_val(TreeNode *root)
{
    if (root->right == NULL)
        return root->val;
    return max_val(root->right);
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
        //node with key value have no childs.
        if (root->left == nullptr && root->right == nullptr)
            return NULL;

        else if (root->right != nullptr && root->left != nullptr)
        {
            //node with key value having both left and right child.
            //node having both childs will be replaced by the the max value of its left sub tree,
            //bcz, in the left subtree max value will have no right child.
            //and it will be easy to remove the nodes with zero or 1 child.
            int mx = max_val(root->left);
            root->val = mx;
            cout << mx;
            root->left = deleteNode(root->left, mx);
            return root;
        }
        else
        {
            //node with key value having either left or right child only.
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
    root=deleteNode(root, x);
    //Root value must be updated, 
    cout << "\nThe inorder of tree is : ";
    print(root);
}

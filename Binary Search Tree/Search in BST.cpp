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
bool search(int x, TreeNode *root)
{
    if (root == NULL)
        return false;
    else if (root->val == x)
        return x;
    else if (root->val > x)
        return search(x, root->left);
    else if (root->val < x)
        return search(x, root->right);
    return false;
}
int main()
{
    TreeNode *root = BuildTree();
    int x;
    cout << "The inorder of Tree is : ";
    print(root);
    cout << "\nEnter the value to be searched : ";
    cin >> x;
    cout << "\nIs present " << x << boolalpha << " :" << search(x, root);
}

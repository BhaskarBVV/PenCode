#include <bits/stdc++.h>
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
TreeNode *BuildTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    TreeNode *Node = new TreeNode(d);
    cout << "Enter left child of " << d << " : ";
    Node->left = BuildTree();
    cout << "Enter right child of " << d << " : ";
    Node->right = BuildTree();
    return Node;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}
bool is_BST(TreeNode *root, int min, int max)
{
    if (root == NULL)
        return true;
    return is_BST(root->left, min, root->val) && is_BST(root->right, root->val, max) && ((root->val > min && root->val < max) ? true : false);
}
int main()
{
    cout << "Build Tree : ";
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    cout << "\nIs tree BST : " << boolalpha << is_BST(root, INT_MIN, INT_MAX);
    cout << endl;
}

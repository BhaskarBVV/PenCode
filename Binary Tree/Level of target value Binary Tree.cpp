//Bhaskar Varshney
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
    cout << "Enter the left child of " << d << " : ";
    Node->left = BuildTree();
    cout << "Enter the right child of " << d << " : ";
    Node->right = BuildTree();
    return Node;
}
void Level(TreeNode *root, int k, int l, int &x)
{
    if (root == NULL)
        return;
    if (root->val == k)
        x = l;
    Level(root->left, k, l + 1, x);
    Level(root->right, k, l + 1, x);
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}
int main()
{
    cout << "Build first tree : ";
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    int x = 0, l = 1, k;
    cout << "\nEnter the target node : ";
    cin >> k;
    Level(root, k, l, x);
    cout << "The level of node is : " << x << endl;
}

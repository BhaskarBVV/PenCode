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
void NodeAtDstK(TreeNode *root, int k, int x, vector<int> &v)
{
    if (root == NULL)
        return;
    NodeAtDstK(root->left, k, x + 1, v);
    if (k == x)
        v.push_back(root->val);
    NodeAtDstK(root->right, k, x + 1, v);
}
int main()
{
    cout << "Build Tree : ";
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    int x;
    cout << "\nEnter the distance between node and root : ";
    cin >> x;
    vector<int> v;
    NodeAtDstK(root, x, 0, v);
    for (auto it : v)
        cout << it << " ";
}

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
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}
void treeHelper(TreeNode *root, TreeNode *&pre, TreeNode *&suc, int k, int &state)
{
    if (root == NULL)
        return;
    // cout<<"pre"<<root->key<<endl;
    treeHelper(root->left, pre, suc, k, state);
    // cout << "In" << root->val << endl;
    if (state == 0)
    {
        if (root->val == k)
            state = 1;
        else
            pre = root;
    }
    else if (state == 1)
    {
        suc = root;
        state = 2;
    }
    treeHelper(root->right, pre, suc, k, state);
    // cout<<"post"<<root->key<<endl;
}
int main()
{
    cout << "Build Tree : ";
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    int state = 0;
    TreeNode *pre = NULL, *suc = NULL;
    int k;
    cout << "\nEnter Key : ";
    cin >> k;
    treeHelper(root, pre, suc, k, state);
    if (pre)
        cout << "Pre : " << pre->val << endl;
    else
        cout << "Pre : " << -1 << endl;
    if (suc)
        cout << "Suc : " << suc->val;
    else
        cout << "Suc : " << -1 << endl;
}

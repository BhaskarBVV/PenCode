#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) :  val(x), left(left), right(right) {}
};
// there will be three cases, the diameter may pass through root
//secondly, the diameter would only be in the left part of rootnode 
// or the diameter would only be in right part of root node;
// Note that the root node of subtree is also called root node,
// The diameter of all leaf nodes are zeros, 
// and height of every node is retuned in ls or rs,
// which are used to find 
// height and then diamater.
TreeNode *BuildTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    TreeNode *Node = new TreeNode(d);
    Node->left = BuildTree();
    Node->right = BuildTree();
    return Node;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val;
    print(root->left);

    print(root->right);
}
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}
int diameter(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int op1 = lh + rh;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op2, op3));
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    cout << endl;
    cout << "The daimeter of binary tree : " << diameter(root);
}

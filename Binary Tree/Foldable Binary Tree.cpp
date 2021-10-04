// A tree can be folded if left and right subtrees of the tree are structure wise same.
//        10
//      /    \
//     7      15  Foldable
//      \    /
//       9  11
         
//         10
//        /  \
//       7    15  Foldable
//      /      \
//     9       11

//         10
//        /  \
//       7   15   Foldable
//      /    /
//     5   11

// Bhaskar Varshney
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
bool treeHelper(TreeNode *a, TreeNode *b)
{
    if (a == NULL && b == NULL)
        return true;
    if (a == NULL || b == NULL)
        return false;
    return treeHelper(a->left, b->right) && treeHelper(a->right, b->left);
}
bool IsFoldable(TreeNode *root)
{
    if (root == NULL)
        return true;
    return treeHelper(root->left, root->right);
}
int main()
{
    cout << "Build Tree : ";
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    cout << "Is Foldable : " << boolalpha << IsFoldable(root);
}

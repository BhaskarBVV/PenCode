// INPUT:
// T1:     1     T2:     1
//       /   \         /   \
//      2     3       3     2
// Output: 1

// Input:
// T1:     10      T2:   10
//        /  \          /  \
//       20  30        20  30
//      /  \          /  \
//     40   60       40  60
// Output: 0

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
int areMirror(TreeNode *a, TreeNode *b)
{
    if (a == NULL && b == NULL)
        return 1;
    if (a == NULL || b == NULL)
        return 0;
    int x = 0;
    if (a->val == b->val)
        x = 1;
    return x && areMirror(a->left, b->right) && areMirror(a->right, b->left);
}
int main()
{
    cout << "Build Tree 1st : ";
    TreeNode *root1 = BuildTree();
    cout << "\nPreOrder of Tree is: ";
    print(root1);
    cout << "\nBuild Tree 2nd : ";
    TreeNode *root2 = BuildTree();
    cout << "\nPreOrder of Tree 2 is: ";
    print(root2);
    cout << "\nAre both trees mirror of each other : " << boolalpha << areMirror(root1, root2);
}

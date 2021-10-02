// Input:
//          5
//        /   \
//       1     1
//      /       \
//     2         2
// Output: True
// Explanation: Tree is mirror image of itself i.e. tree is symmetric

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
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}
// For mirror left should be similar to right image and right should be similar to left image.

bool are_same(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if ((p == NULL && q != NULL) || (q == NULL && p != NULL))
        return false;
    if (p->val != q->val)
        return false;
    // for every sub-root node the left sub-tree should be equal to right sub tree
    // therefore one pointer moves to left and other to right of root.
    return are_same(p->left, q->right) && are_same(p->right, q->left);
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    // The given tree is broken in two halves, left and right
    // and their pointers are sent for checking...
    return are_same(root->left, root->right);
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "Inorder of Tree is: ";
    print(root);
    cout << endl;
    cout << "Is the tree mirror of itself : " << boolalpha << isSymmetric(root);
}

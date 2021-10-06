// Input:
// T:      1          S:   3
//       /   \            /
//      2     3          4
//    /  \    /
//   N    N  4
// Output: 1 
// Explanation: S is present in T

// Subtree should be upto end of tree,

// T:       1          S:   3
//       /    \            /    
//      2      3          4
//    /  \    / \
//   4   5   6    7
// /  \    \
//9   10    11

// Now, this second tree is not subtree of first;

//Bhaskar Varshney
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *nextRight;
    TreeNode() : val(0), left(nullptr), right(nullptr), nextRight(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), nextRight(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *nextRight) : val(x), left(left), right(right), nextRight(nextRight) {}
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
void InOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}
bool is_identical(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    return is_identical(root1->left, root2->left) && is_identical(root1->right, root2->right) && (root1->val == root2->val) ? true : false;
}
bool isSubTree(TreeNode *root1, TreeNode *root2)
{
    bool x = false;
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 != NULL && root2 == NULL)
        return true;
    if (root1 == NULL && root2 != NULL)
        return false;
    if (root1->val == root2->val)
    {
        x = is_identical(root1, root2);
    }
    return isSubTree(root1->left, root2) || isSubTree(root1->right, root2) || x;
}
int main()
{
    cout << "Build Tree : ";
    TreeNode *root1 = BuildTree();
    cout << "InOrder tra. of tree will be : ";
    InOrder(root1);
    cout << "\nBuild 2nd tree to be checked if subtree : ";
    TreeNode *root2 = BuildTree();
    cout << "InOrder tra. of Sub-tree will be : ";
    InOrder(root2);
    cout << "\nIs given tree subTree of first : " << boolalpha << isSubTree(root1, root2);
}

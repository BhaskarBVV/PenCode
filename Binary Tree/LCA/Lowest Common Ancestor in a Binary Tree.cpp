//Bhaskar Varshney
// Input:
// n1 = 3 , n2 = 4
//          5
//         /
//        2
//      /  \
//     3    4
// Output: 2
// Explanation: 
// LCA of 3 and 4 is 2. 

// return a node with value -1 if both n1 and n2 is not present in the tree.

#include <iostream>
#include <queue>
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
    cout << "enter left child of " << d << " : ";
    Node->left = BuildTree();
    cout << "enter right child of " << d << " : ";
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
TreeNode *treeHelper(TreeNode *root, int a, int b)
{
    if (root == NULL)
        return NULL;
    if (root->val == a)
        return root;
    if (root->val == b)
        return root;
    TreeNode *l = treeHelper(root->left, a, b);
    TreeNode *r = treeHelper(root->right, a, b);
    if (l == NULL && r == NULL)
        return NULL;
    if (l != NULL && r != NULL)
        return root;
    if (l)
        return l;
    return r;
}
TreeNode *lca(TreeNode *root, int n1, int n2)
{
    TreeNode *LCA = treeHelper(root, n1, n2);
    if (LCA == NULL)
    {
        TreeNode *NewNode = (TreeNode *)malloc(sizeof(TreeNode));
        NewNode->val = -1;
        return NewNode;
    }
    return LCA;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "Preorder of tree is: ";
    print(root);
    int a, b;
    cout << "\nEnter the nodes whose LCA is to be calculated : ";
    cin >> a >> b;
    cout << "The LCA is : " << lca(root, a, b)->val;
}

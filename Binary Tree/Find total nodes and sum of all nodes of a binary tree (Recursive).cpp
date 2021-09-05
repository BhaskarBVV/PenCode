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
int totalNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}
int sumOfNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    cout << endl;
    cout << "Total nodes in binary tree : "
         << totalNodes(root) << endl;
    cout << "Total sum of all nodes will be: " 
         << sumOfNodes(root);
}
//-----------------------------------------------END OF CODE---------------------------------------------------------------------------------------
//-----------------------------------------A Bit Explaination of code-------------------------------------------------------------------------------
//In order to get the sum of nodes of binary tree,  add the value of the root node, and move to the left subtree and right subtree, 
//if root have reached to the end, i.e. after root->left=0, root will store 0, in that case return 0.

// long int sumBT(Node* root)
// {
//     if (root==0)
//     return 0;
//     else 
//     return root->key+sumBT(root->right)+sumBT(root->left);
// }

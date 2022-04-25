// Input : 
//           1
//         /   \
//        2     5
//       / \     \
//      3   4     6
// Output :
// 1 2 3 4 5 6 
// Explanation: After flattening, the tree looks 
// like this
//     1
//      \
//       2
//        \
//         3
//          \
//           4
//            \
//             5
//              \
//               6 
// Here, left of each node points to NULL and right contains the next node in preorder.The inorder traversal of this flattened tree is 1 2 3 4 5 6.
  
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
void flatten(TreeNode *root)
{
  Here we have to first push right than left bcz root's right should become left sib node and right sub node should become right of left subnode, and left of every will become NULL.
    if (root == NULL)
        return;
    stack<TreeNode *> s;
    s.push(root);
    TreeNode *temp = NULL;
    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
        if (!s.empty())
            temp->right = s.top();
        temp->left = NULL;
    }
}
int main()
{
    cout << "Build Tree : ";
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    flatten(root);
    cout << "\nInOrder traversal after flattening : ";
    print(root);
}

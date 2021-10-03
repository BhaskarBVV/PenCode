// Input:
//              10
//           /      \
//         -2        6
//        /   \     /  \
//      8     -4   7    5

// Output:
//             20
//           /    \
//         4        12
//        /  \     /  \
//      0     0   0    0

// Explanation:

//            (4-2+12+6)
//           /           \
//       (8-4)          (7+5)
//        /   \         /  \
//       0     0       0    0


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
void InOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}
int toSumTree(TreeNode *root)
{
    int temp;
    if (root == NULL)
    {
        return 0;
    }
    int left_sum = toSumTree(root->left);
    int right_sum = toSumTree(root->right);
    temp = root->val;
    root->val = left_sum + right_sum;
    return root->val + temp;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << endl;
    cout << "InOrder of tree is : ";
    InOrder(root);
    int x = toSumTree(root);
    cout << "\nThe InOrder of transformed Sum Tree : ";
    InOrder(root);
}

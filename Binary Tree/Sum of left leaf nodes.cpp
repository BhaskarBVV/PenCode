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
    cout << root->val;
    print(root->left);
    print(root->right);
}
void treeHelper(TreeNode *root, int &sum)
{
    if (root == NULL)
        return;
    if (root->left != NULL && (root->left->left == NULL && root->left->right == NULL))
        sum += root->left->val;
    treeHelper(root->left, sum);
    treeHelper(root->right, sum);
}
int leftLeavesSum(TreeNode *root)
{
    int sum = 0;
    treeHelper(root, sum);
    return sum;
}
int main()
{
    cout << "Build first tree : ";
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    cout << "The sum of left leaf node : " << leftLeavesSum(root);
}

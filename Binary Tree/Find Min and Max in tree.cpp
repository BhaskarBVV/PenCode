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
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}
int findMax(TreeNode *root)
{
    if (root == NULL)
        return INT_MIN;
    int left_max = findMax(root->left);
    int right_max = findMax(root->right);
    return max(root->val, max(left_max, right_max));
}
int findMin(TreeNode *root)
{
    if (root == NULL)
        return INT_MAX;
    int left_min = findMin(root->left);
    int right_min = findMin(root->right);
    return min(root->val, min(left_min, right_min));
}
int main()
{
    cout << "Build Tree : ";
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    cout << "\nMin value : " << findMin(root) << endl;
    cout << "\nMax value : " << findMax(root) << endl;
}

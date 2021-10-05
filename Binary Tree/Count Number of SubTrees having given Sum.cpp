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
int treeHelper(TreeNode *root, int x, int &cnt)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL && root->val == x)
    {
        cnt += 1;
        return root->val;
    }
    int l = treeHelper(root->left, x, cnt);
    int r = treeHelper(root->right, x, cnt);
    root->val = root->val + l + r;
    if (root->val == x)
        cnt += 1;
    return root->val;
}
int countSubtreesWithSumX(TreeNode *root, int x)
{
    int cnt = 0;
    treeHelper(root, x, cnt);
    return cnt;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << endl;
    cout << "PreOrder of tree is : ";
    InOrder(root);
    int sum = 0;
    cout << "\nEnter the desired sum : ";
    cin >> sum;
    cout << "\nThe number of subtrees with required sum are : " << countSubtreesWithSumX(root, sum);
}

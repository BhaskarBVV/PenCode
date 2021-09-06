#include <iostream>
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
TreeNode *BuildTree(int a[], int s, int e)
{
    if (s > e)
        return NULL;
    int mid = (e + s) / 2;
    TreeNode *root = new TreeNode(a[mid]);
    root->left = BuildTree(a, s, mid - 1);
    root->right = BuildTree(a, mid + 1, e);
    return root;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}
void modify(TreeNode *root, int &sum)
{
    // Use reverse inorder traversal (Right->Root->Left), storing the sum of all nodes in a static varible that can be used to modify the nodes with smaller value;
    // Reached to the righest end of Tree(max value) and started changing from there.
    int y;
    if (root == NULL)
        return;
    modify(root->right, sum);
    y = root->val;
    root->val = sum + root->val;
    sum += y;
    modify(root->left, sum);
}
int main()
{
    //building a tree from inorder traversal.
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    TreeNode *root = BuildTree(a, 0, n - 1);
    int sum = 0;
    //replacing the node with sum of itself and those whose value are greater than it.
    modify(root, sum);
    cout << "The preOrder of modified Tree is: ";
    print(root);
}

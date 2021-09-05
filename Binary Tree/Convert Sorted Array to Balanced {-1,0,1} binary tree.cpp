#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) :  val(x), left(left), right(right) {}
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
TreeNode *buildTreeFromSortedArray(vector<int> &v, int s, int e)
{
    if (s > e)
        return NULL;
    int mid = (s + e) / 2;
    TreeNode *root = new TreeNode(v[mid]);
    root->left = buildTreeFromSortedArray(v, s, mid - 1);
    root->right = buildTreeFromSortedArray(v, mid + 1, e);
    return root;
}
int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = buildTreeFromSortedArray(v, 0, v.size() - 1);
    cout << "The PreOrder of Tree is: ";
    print(root);
}

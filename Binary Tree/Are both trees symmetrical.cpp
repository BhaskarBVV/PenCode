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
bool are_symmetric(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    else if ((p == NULL && q != NULL) || (q == NULL && p != NULL))
        return false;
    else
    {
        return are_symmetric(p->left, q->left) && are_symmetric(p->right, q->right);
    }
}
int main()
{
    cout << "Build first tree : ";
    TreeNode *root1 = BuildTree();
    cout << "PreOrder of first Tree is: ";
    print(root1);
    cout << "\nBuild second tree : ";
    TreeNode *root2 = BuildTree();
    cout << "PreOrder of second Tree is: ";
    print(root2);
    cout << "\nAre both trees same : " << boolalpha << are_symmetric(root1, root2);
    cout << endl;
}

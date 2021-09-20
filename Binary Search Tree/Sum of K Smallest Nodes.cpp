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
TreeNode *insert(int d, TreeNode *root)
{
    if (root == NULL)
        return new TreeNode(d);
    else if (root->val == d)
        return root;
    else if (root->val < d)
        root->right = insert(d, root->right);
    else if (root->val > d)
        root->left = insert(d, root->left);
    return root;
}
TreeNode *BuildTree()
{
    TreeNode *root = NULL;
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    while (d != -1)
    {
        root = insert(d, root);
        cout << "Enter another Value to be entered : ";
        cin >> d;
    }
    return root;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}
int GetSum(TreeNode *root, int &k, int &sum)
{
    if (root == NULL)
        return 0;
    GetSum(root->left, k, sum);
    if (k != 0)
    {
        sum += root->val;
        k -= 1;
        GetSum(root->right, k, sum);
    }
    return sum;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "The inorder of Tree is : ";
    print(root);
    int k, sum = 0;
    cout << "\nEnter the value of k : ";
    cin >> k;
    sum = GetSum(root, k, sum);
    cout << "The sum of K smallest elements is : ";
    cout << sum;
}

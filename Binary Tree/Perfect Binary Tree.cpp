//         1   level = 0
//       /  \ 
//      2    3 level = 1
//    /     / \
//   6      4   5 level = 2  height of tree=3 so hight=level+1
          
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
int get_height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int ls = get_height(root->left);
    int rs = get_height(root->right);
    return max(ls, rs) + 1;
}

bool treeHelper(TreeNode *root, int h, int l)
{
    if (root == NULL)
        return true;
    if (root->right == NULL && root->left == NULL)
    {
        if (h == l + 1)
            return true;
        else
            return false;
        // return (l+1==h);
    }
    if (root->right == NULL || root->left == NULL)
        return false;
    return treeHelper(root->right, h, l + 1) && treeHelper(root->left, h, l + 1);
}

bool isPerfect(TreeNode *root)
{
    int max_h = get_height(root);
    int level = 0;
    return treeHelper(root, max_h, level);
}
int main()
{
    cout << "Build first tree : ";
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    cout << "\nIs tree Pefect : " << boolalpha << isPerfect(root);
}

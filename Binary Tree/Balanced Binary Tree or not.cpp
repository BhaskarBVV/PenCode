#include <bits/stdc++.h>
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
class pairr
{
public:
    int height;
    bool balanced;
};
TreeNode *BuildTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    TreeNode *Node = new TreeNode(d);
    Node->left = BuildTree();
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
pairr isBalanced(TreeNode *root)
{
    pairr p;
    if (root == NULL)
    {
        p.height = 0;
        p.balanced = true;
        return p;
    }
    pairr left = isBalanced(root->left);
    pairr right = isBalanced(root->right);
    p.height = max(left.height, right.height) + 1;
    if (abs(left.height - right.height) <= 1 && right.balanced && left.balanced)
        p.balanced = true;
    else
        p.balanced = false;
    return p;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    cout << endl;
    cout << "Is tree balanced: " << isBalanced(root).balanced;
}

// In this also we are moving from bottom to top,
// i.e first we've reached to the leaf nodes by repeatedly
// calling recursive functions and then building up.

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
class pairr
{
public:
    int hgt;
    int dia;
};

// If we are counting dia or height on basis of number of edges, then for NULL height=-1;
// and if on basis of number of nodes, then for NULL height=0;

pairr diameter(TreeNode *root)
{
    pairr p;
    if (root == NULL)
    {
        p.hgt = 0;
        p.dia = 0;
        return p;
    }
    pairr left = diameter(root->left);
    pairr right = diameter(root->right);

    p.hgt = max(left.hgt, right.hgt) + 1;
    p.dia = max(left.hgt + right.hgt + 1, max(left.dia, right.dia));
  // (left.hgt + right.hgt + 1) there is only one node between left and right subtree if dia passes through root node,
    return p;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    cout << endl;
    cout << "The daimeter of binary tree : " << diameter(root).dia;
}

// In this approach we are moving from bottom to top,
// building from bottom both height and diameter,
// hence we do not need to call height function again for every node;

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
vector<int> PreOrder(TreeNode *root)
{
    vector<int> v;
    stack<TreeNode *> s;
    TreeNode *x;
    s.push(root);
    while (!s.empty())
    {
        x = s.top();
        s.pop();
        v.push_back(x->val);
        // since in preOrder we move from root->left->right.
        // And in stack we can access only those values which are at top of stack
        // Hence, in order to access left before right, we must push right at first and then left
        // So, that left comes at top and we can easily access left.
        if (x->right)
            s.push(x->right);
        if (x->left)
            s.push(x->left);
    }
    return v;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << endl;
    cout << "PreOrder of tree : ";
    vector<int> v = PreOrder(root);
    for (auto it : v)
        cout << it << " ";
}

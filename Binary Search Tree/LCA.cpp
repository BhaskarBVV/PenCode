// If both n1 and n2 are smaller than data at current node, call the function recursively for finding LCA in the left subtree.
// If both n1 and n2 are greater than data at current node, call the function recursively for finding LCA in the right subtree.
// Otherwise, current node is LCA (assuming that both n1 and n2 are present in BST)
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
void bfs(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->val << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}
TreeNode *LCA(TreeNode *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->val > n1 && root->val > n2)
        return LCA(root->left, n1, n2);
    if (root->val < n1 && root->val < n2)
        return LCA(root->right, n1, n2);
    if ((root->val >= n1 && root->val <= n2) || (root->val <= n1 && root->val >= n2))
        return root;
    return NULL;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "The inorder of Tree is : ";
    print(root);
    cout << "\nThe level order traversal will be : \n";
    bfs(root);
    int a, b;
    cout << "\nEnter the Keys : ";
    cin >> a >> b;
    cout << "\nThe LCA is : " << LCA(root, a, b)->val;
}

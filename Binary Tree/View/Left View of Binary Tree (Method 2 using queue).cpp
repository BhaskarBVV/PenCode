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
void LeftView(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    TreeNode *temp;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
//don't change the order of pushing first right child and then left child.
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (q.front() == NULL)
                cout << temp->val << " ";
        }
    }
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "Preorder of tree is: ";
    print(root);
    cout << "\nThe Left view is: ";
    LeftView(root);
}


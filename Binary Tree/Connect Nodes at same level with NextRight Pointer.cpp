// Input:
//       10
//     /   \
//    20   30
//   /  \
//  40  60
// Output:
// 40 20 60 10 30
//   Explanation:The connected tree is
//          10 ----------> NULL
//        /     \
//      20 ------> 30 -------> NULL
//   /    \
//  40 ----> 60 ----------> NULL

//Bhaskar Varshney
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *nextRight;
    TreeNode() : val(0), left(nullptr), right(nullptr), nextRight(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), nextRight(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *nextRight) : val(x), left(left), right(right), nextRight(nextRight) {}
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
void InOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}
void connect(TreeNode *root)
{
    queue<TreeNode *> q;
    TreeNode *temp = NULL;
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
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            temp->nextRight = q.front();
        }
    }
}

int main()
{
    TreeNode *root = BuildTree();
    cout << endl;
    cout << "PreOrder of tree is : ";
    InOrder(root);
}

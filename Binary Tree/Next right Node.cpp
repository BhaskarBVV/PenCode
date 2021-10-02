// Input:
//           10
//      /    \
//     2      6
//    / \      \
//   8   4      5
// and key = 2
// Output: 6
// If there is no node on right side, then return a node with value -1.


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
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}
TreeNode *nextRight(TreeNode *root, int key)
{
    queue<TreeNode *> q;
    TreeNode *temp = NULL, *ans = NULL;
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
            if (temp->val == key)
            {
                if (q.empty() || q.front() == NULL)
                {
                    return new TreeNode(-1);
                    break;
                }
                else
                {
                    ans = q.front();
                    break;
                }
            }
        }
    }
    return ans;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << endl;
    cout << "PreOrder of tree is : ";
    print(root);
    int x;
    cout << "\nEnter the key whose Right value is to be printed: ";
    cin >> x;
    cout << "The Node to the right is : " << nextRight(root, x)->val;
}

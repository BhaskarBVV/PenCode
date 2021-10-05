//       2
//     /    \ 
//    1      3
//  /   \     \
// 4    6      8
//      / 
//     5
// Output: 2
// Explanation: The level 2 with nodes 4, 6 and 8 is the level with maximum number of nodes. 
  
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
void InOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}
int maxNodeLevel(TreeNode *root)
{
    int mx = -1;
    int mx_l = -1;
    int cnt = 0;
    int l = 0;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    TreeNode *temp = NULL;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            if (cnt > mx)
            {
                mx_l = l;
                mx = cnt;
            }
            cnt = 0;
            l += 1;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cnt++;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return mx_l;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << endl;
    cout << "PreOrder of tree is : ";
    InOrder(root);
    cout << "\nThe level with max nodes : " << maxNodeLevel(root);
}

//                      20
//                    /    \
//                   8      22
//                  / \    / \
//                 5   3  4   25
//                     /   \      
//                    10    14
// For the above tree the output should be 5 10 4 14 25.
// Store last value corressponding to every vertical line in map from queue, and finally from map to vector.

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
    cout << "Enter left child of " << d << " : ";
    Node->left = BuildTree();
    cout << "Enter right child of " << d << " : ";
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
vector<int> bottomView(TreeNode *root)
{
    if (root == NULL)
        return {};
    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));
    pair<TreeNode *, int> temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        mp[temp.second] = temp.first->val;
        if (temp.first->left)
            q.push(make_pair(temp.first->left, temp.second - 1));
        if (temp.first->right)
            q.push(make_pair(temp.first->right, temp.second + 1));
    }
    vector<int> v;
    for (auto it : mp)
    {
        v.push_back(it.second);
    }
    return v;
}
int main()
{
    cout << "Build Tree : ";
    TreeNode *root1 = BuildTree();
    cout << "InOrder tra. of tree will be : ";
    InOrder(root1);
    vector<int> v = bottomView(root1);
    cout << "\nThe Bottom view wil be : ";
    for (auto it : v)
        cout << it << " ";
}

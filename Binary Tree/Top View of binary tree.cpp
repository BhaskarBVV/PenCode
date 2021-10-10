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
// Root node will have vertical line 0, any child node left to it will have vertical line = (current line-1) and for right child (current line+1).
// Each time we will push Node with its vertical line in queue,
// For each node at front of queue we will push left and right child with their verical lines, 
// for each node at front of queue, if its corressponding vertical line is not present in map, than insert that node value for that vertical line, 
// and if that vertical line is already present than do nothing other than pushing its left and right child into the queue.
vector<int> topView(TreeNode *root)
{
    map<int, int> mp;
    pair<TreeNode *, int> temp;
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (mp.find(temp.second) == mp.end())
            mp[temp.second] = temp.first->val;
        if (temp.first->left)
            q.push(make_pair(temp.first->left, temp.second - 1));
        if (temp.first->right)
            q.push(make_pair(temp.first->right, temp.second + 1));
    }
    vector<int> v;
    for (auto it : mp)
        v.push_back(it.second);
    return v;
}
int main()
{
    cout << "Build Tree : ";
    TreeNode *root1 = BuildTree();
    cout << "InOrder tra. of tree will be : ";
    InOrder(root1);
    vector<int> v = topView(root1);
    cout << "\nThe top view wil be : ";
    for (auto it : v)
        cout << it << " ";
}

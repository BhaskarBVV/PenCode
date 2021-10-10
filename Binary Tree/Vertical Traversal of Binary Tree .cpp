// Input:
//            1
//          /   \
//        2       3
//      /   \   /   \
//    4      5 6      7
//               \      \
//                8      9           
// Output: 
// 4 2 1 5 6 3 8 7 9 

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
vector<int> verticalOrder(TreeNode *root)
{
    map<int, vector<int>> mp;
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));
    pair<TreeNode *, int> temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        mp[temp.second].push_back(temp.first->val);
        if (temp.first->left)
            q.push(make_pair(temp.first->left, temp.second - 1));
        if (temp.first->right)
            q.push(make_pair(temp.first->right, temp.second + 1));
    }
    vector<int> v;
    for (auto it : mp)
    {
        for (auto it1 : it.second)
            v.push_back(it1);
    }
    return v;
}
int main()
{
    cout << "Build Tree : ";
    TreeNode *root1 = BuildTree();
    cout << "InOrder tra. of tree will be : ";
    InOrder(root1);
    vector<int> v = verticalOrder(root1);
    cout << "\nThe vertical view wil be : ";
    for (auto it : v)
        cout << it << " ";
}

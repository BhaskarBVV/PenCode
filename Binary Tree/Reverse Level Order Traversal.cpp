// Input :
//         1
//       /   \
//      3     2

// Output: 3 2 1
// Explanation:
// Traversing level 1 : 3 2
// Traversing level 0 : 1

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
    cout << "Enter left child of " << d << " : ";
    Node->left = BuildTree();
    cout << "Enter right child of " << d << " : ";
    Node->right = BuildTree();
    return Node;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}
vector<int> reverseLevelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    TreeNode *temp = NULL;
    vector<int> v;
    q.push(root);
    while (!q.empty())
    {
        // In reverse level order traversal we first have to push right child befre left child and reverse entire vector at end
        temp = q.front();
        q.pop();
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
        v.push_back(temp->val);
    }
    reverse(v.begin(), v.end());
    return v;
}
int main()
{
    cout << "Build Tree : ";
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    vector<int> v = reverseLevelOrder(root);
    cout << "\nReverse Level Order traversal : ";
    for (auto it : v)
        cout << it << " ";
}

// Input:
//            1
//          /    \
//        2       3
//       /   \
//     4     5
// Output: 4 2 5 1 3

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

// In the inorder traversal we have to move to the leftmost node without printing at same time and when there is no node to left we print that left node
// Now we have leftmost node in our hand, if there is any right node to it we've moved on it bcz (inorder left->root->right) (left node of leftmost node is not present)
// Again if there is no node to right (right child) for the leftmost node , i.e, leftmost->right==NULL, we will pick node root node of leftmost node from satck,
// print it and move towards the right of it and so on.

vector<int> inOrder(TreeNode *root)
{
    stack<TreeNode *> s;
    vector<int> v;
    TreeNode *temp = root;
    while (1)
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            if (s.empty())
                break;
            temp = s.top();
            v.push_back(temp->val);
            s.pop();
            temp = temp->right;
        }
    }
    return v;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << endl;
    cout << "InOrder of tree : ";
    vector<int> v = inOrder(root);
    for (auto it : v)
        cout << it << " ";
}

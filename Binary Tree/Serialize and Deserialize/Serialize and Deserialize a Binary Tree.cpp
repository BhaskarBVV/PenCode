// Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. 

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

// In serialize i've calculated level order traversal with (-1) present for every node if its child is not present, NULL does not represent every level.
// Instead it states here that the given root doesnot have a child node. And for every NUll we will insert (-1) in vector.
vector<int> serialize(TreeNode *root)
{
    if (root == NULL)
        return {};
    queue<TreeNode *> q;
    q.push(root);
    vector<int> v;
    TreeNode *temp = NULL;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            else
                q.push(NULL);
            if (temp->right)
                q.push(temp->right);
            else
                q.push(NULL);
        }
    }
    return v;
}
//DeSerialize can also be done through recursion, but this is iteartive approach.
TreeNode *deSerialize(vector<int> &v)
{
    if (v.empty())
        return NULL;
    TreeNode *root = new TreeNode(v[0]);
    queue<TreeNode *> q;
    int i = 0;
    q.push(root);
    TreeNode *temp = NULL;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (2 * i + 1 < v.size())
        {
            if (v[2 * i + 1] != -1)
            {
                temp->left = new TreeNode(v[2 * i + 1]);
                q.push(temp->left);
            }
            else
                temp->left = NULL;
        }
        if (2 * i + 2 < v.size())
        {
            if (v[2 * i + 2] != -1)
            {
                temp->right = new TreeNode(v[2 * i + 2]);
                q.push(temp->right);
            }
            else
                temp->right = NULL;
        }
        i += 1;
    }
    return root;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "InOrder tra. of tree will be : ";
    InOrder(root);
    vector<int> v = serialize(root);
    cout << "\nThe serialized tree is : ";
    for (auto it : v)
        cout << it << " ";
    root = deSerialize(v);
    cout << "\nThe inorder traversal of tree formed serialize vector will be : ";
    InOrder(root);
}

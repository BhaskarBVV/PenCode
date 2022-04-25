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
    int x;
    TreeNode *temp;
    queue<TreeNode *> q;
    cin >> x;
    if (x == -1)
        return NULL;
    TreeNode *root = new TreeNode(x);
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        cin >> x;
        if (x != -1)
        {
            temp->left = new TreeNode(x);
            q.push(temp->left);
        }
        cin >> x;
        if (x != -1)
        {
            temp->right = new TreeNode(x);
            q.push(temp->right);
        }
    }
    return root;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;

    print(root->left);
    cout << root->val;
    print(root->right);
}
void bfs(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->val << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}
int main()
{
    cout << "Create the tree : ";
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    cout << endl;
    cout << "Level order traversal will be: \n";
    bfs(root);
}


//The input must be complete description of all the nodes,
//like ex-> 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1 (-1 means the node doesn't have child)
//the tree formed will be like as->
//                     1
//                 2       3
//               4   5       6  

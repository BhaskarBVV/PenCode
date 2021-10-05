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
void PostOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << " ";
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
TreeNode *treeHelper(int pre[], int s, int e)
{
    if (s > e)
        return NULL;
    TreeNode *root = new TreeNode(pre[s]);
    int i;
    for (i = s + 1; i <= e; i++)
        if (pre[i] > pre[s])
            break;
    root->left = treeHelper(pre, s + 1, i - 1);
    root->right = treeHelper(pre, i, e);
    return root;
}
TreeNode *Build_Tree_from_preOrder(int pre[], int n)
{
    return treeHelper(pre, 0, n - 1);
}
int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;
    int pre[n];
    cout << "Enter the preOrder : ";
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    TreeNode *root = Build_Tree_from_preOrder(pre, n);
    cout << endl;
    cout << "\nLevel Order traversal will be : \n";
    bfs(root);
    cout << "\nPostOrder of tree is : ";
    PostOrder(root);
}

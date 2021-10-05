// Input:
// n=6
// postOrder: 1 7 5 50 40 10

// Output:
// Inorder: 1 5 7 10 40 50
//   Tree will be : 
//        10
//      /   \
//    5       40
//  /   \      \
// 1     7      50

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
void PreOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
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
TreeNode *treeHelper(int post[], int s, int e)
{
    if (s > e)
        return NULL;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->val = post[e];
    int i;
    for (i = 0; i < e; i++)
        if (post[i] > post[e])
            break;
    root->left = treeHelper(post, s, i - 1);
    root->right = treeHelper(post, i, e - 1);
    return root;
}
TreeNode *Build_Tree_from_postOrder(int post[], int n)
{
    return treeHelper(post, 0, n - 1);
}
int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;
    int post[n];
    cout << "Enter the postOrder : ";
    for (int i = 0; i < n; i++)
        cin >> post[i];
    TreeNode *root = Build_Tree_from_postOrder(post, n);
    cout << endl;
    cout << "\nLevel Order traversal will be : \n";
    bfs(root);
    cout << "\nPreOrder of tree is : ";
    PreOrder(root);
}

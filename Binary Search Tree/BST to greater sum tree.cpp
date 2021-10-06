// Input:
//            2
//          /    \
//         1      6
//               /  \
//              3    7
// Output: 18 16 13 7 0 (InOrder)

// Explanation:
// Every node is replaced with the sum of nodes greater than itself. 
// The resultant tree is:
//                16
//              /    \
//            18       7
//                   /   \
//                  13    0

//Bhaskar Varshney
#include <iostream>
#include <queue>
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
TreeNode *insert(int d, TreeNode *root)
{
    if (root == NULL)
        return new TreeNode(d);
    else if (root->val == d)
        return root;
    else if (root->val < d)
        root->right = insert(d, root->right);
    else if (root->val > d)
        root->left = insert(d, root->left);
    return root;
}
TreeNode *BuildTree()
{
    TreeNode *root = NULL;
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    while (d != -1)
    {
        root = insert(d, root);
        cout << "Enter another Value to be entered : ";
        cin >> d;
    }
    return root;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->val << " ";
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
void transformTree(TreeNode *root, int &sum)
{
    if (root == NULL)
        return;
    transformTree(root->right, sum);
    int temp = root->val;
    root->val = sum;
    sum += temp;
    transformTree(root->left, sum);
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "The inorder of Tree is : ";
    print(root);
    cout << "\nThe level order traversal will be : \n";
    bfs(root);
    int sum = 0;
    transformTree(root, sum);
    cout << "\nThe level order traversal of transformed tree will be : \n";
    bfs(root);
}

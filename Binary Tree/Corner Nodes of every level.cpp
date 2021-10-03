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
void InOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}

// Node whose next value is NULL in queue are rightMost corner Nodes and are printed with help of q.front()==NULL
// and the nodes that comes after NULL in queue are leftMost Nodes and are printed with help of flag, (when NULL is encountered flag is set to 1 and if there is any
// value in temp in next iteration and flag==1 then print that left most node and set flag=0)

void printCorner(TreeNode *root)
{
    queue<TreeNode *> q;
    TreeNode *temp = NULL;
    q.push(root);
    q.push(NULL);
    int flag = 0;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            flag = 1;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            if (flag == 1)
            {
                cout << temp->val << " ";
                flag = 0;
            }
            else if (q.front() == NULL)
            {
                cout << temp->val << " ";
                flag = 1;
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
int main()
{
    TreeNode *root = BuildTree();
    cout << endl;
    cout << "PreOrder of tree is : ";
    InOrder(root);
    cout << "\nThe corner elements are : ";
    printCorner(root);
}

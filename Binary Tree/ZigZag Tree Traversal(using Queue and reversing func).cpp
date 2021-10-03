// Input:             Order of printing
//            7        -->
//         /     \
//        9       12   <--
//      /  \     /   
//     8    8   6      -->
//    /  \
//   10   9            <--
// Output:
// 7 12 9 8 8 6 9 10 


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
vector<int> zigZagTraversal(TreeNode *root)
{
    TreeNode *temp = NULL;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    vector<int> v, v2;
    int flag = 1;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            if (flag == 1)
            {
                for (auto it : v2)
                    v.push_back(it);
            }
            else
            {
                reverse(v2.begin(), v2.end());
                for (auto it : v2)
                    v.push_back(it);
            }
            v2.clear();
            if (!q.empty())
                q.push(NULL);
            flag = 1 - flag;
        }
        else
        {
            v2.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return v;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << endl;
    cout << "PreOrder of tree is : ";
    InOrder(root);
    vector<int> v = zigZagTraversal(root);
    cout << "\nThe Zig zag traversal will be : ";
    for (auto it : v)
        cout << it << " ";
}

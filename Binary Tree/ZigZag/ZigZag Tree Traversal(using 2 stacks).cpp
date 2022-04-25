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

// here we will be using two stacks.
// one is main stack and other is child stack.
// The way we are moving in main stack, in the same order we will push the child nodes in child stack, bcz in they will come out of stack in opposite order to what we puhsed
// and we puhsed them in the order of moving on parent nodes hence they will be printed in opposite order when they come out.

// used flag variable values{1,0,1,0,...}(1 for odd level and 0 for even level), can also increment the value of flag to check level parity.
  
// For first level, flag=1 (Odd level) we move in left ->right direction hence we push child nodes in child stack in the order (root->left and then root->right) for every parent node
// and vice versa for even levels, we move in right->left hence we insert the child nodes in order (root->right and than root->left)
// Once the main stack gets empty, we will change the value of flag variable, so that it may point to next level and also the child stack will now become main stack for next level
// and child stack gets empty


vector<int> zigZagTraversal(TreeNode *root)
{

    stack<TreeNode *> ms, cs;
    int flag = 1;
    TreeNode *temp = NULL;
    vector<int> v;
    ms.push(root);
    while (!ms.empty())
    {
        temp = ms.top();
        ms.pop();
        v.push_back(temp->val);
        if (flag == 1)
        {
            if (temp->left)
                cs.push(temp->left);
            if (temp->right)
                cs.push(temp->right);
        }
        else
        {
            if (temp->right)
                cs.push(temp->right);
            if (temp->left)
                cs.push(temp->left);
        }
        if (ms.empty())
        {
            flag = 1 - flag;
            swap(ms, cs);
            //ms=cs;
            //while(!cs.empty())
            //cs.pop();
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

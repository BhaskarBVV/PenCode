#include <iostream>
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
    cout << "enter left child of " << d << " : ";
    Node->left = BuildTree();
    cout << "enter right child of " << d << " : ";
    Node->right = BuildTree();
    return Node;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}
int RootToChildSum(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int l = RootToChildSum(root->left);
    int r = RootToChildSum(root->right);
    int y = root->val;
    int x = l + r;
    if (x != 0)
        root->val = x;
    return x + y;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    cout << endl;
    int x = RootToChildSum(root);
    cout << "PreOrder of Tree is: ";
    print(root);
}





  //                 8                           63
  //          10           3     To->     23            27  
  //        1    6        4            1      16      13
  //            9 7     13                  9    7   13
              
                      

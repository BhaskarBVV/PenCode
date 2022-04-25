// Input :      
//            6                               
//          /   \                          
//         3     5                      
//       /   \     \
//      2    5      4             
//         /  \                        
//        7    4  

// Output: 13997

// Path                      Number
// 6->3->2                   632
// 6->3->5->7                6357
// 6->3->5->4                6354
// 6->5>4                    654   
// Answer = 632 + 6357 + 6354 + 654 = 13997 
  
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
    cout << "Enter left child of " << d << " : ";
    Node->left = BuildTree();
    cout << "Enter right child of " << d << " : ";
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
void treeHelper(TreeNode *root, long long int val, long long int &sum)
{
    if (root == NULL)
        return;
    if (root->right == NULL && root->left == NULL)
    {
        sum += (val * 10 + root->val);
        return;
    }
    val = val * 10 + root->val;
    treeHelper(root->left, val, sum);
    treeHelper(root->right, val, sum);
}
long long treePathsSum(TreeNode *root)
{
    if (root == NULL)
        return 0;
    long long int sum = 0;
    treeHelper(root, 0, sum);
    return sum;
}
int main()
{
    cout << "Build Tree : ";
    TreeNode *root = BuildTree();
    cout << "PreOrder of Tree is: ";
    print(root);
    cout << "The root to leaf path sum : " << treePathsSum(root);
}

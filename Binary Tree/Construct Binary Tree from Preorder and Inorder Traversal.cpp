#include <iostream>
#include <vector>
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
TreeNode *Build_Tree_Helper(vector<int> pre, vector<int> ino, int preS, int preE, int inS, int inE)
{

    if (preS > preE || inS > inE)
        return NULL;

    //Root node will always be at the beginning of preorder traversal;
    int root_Data = pre[preS];
    //searh the root node in inorder traversal;
    int root_Inorder_Index = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (ino[i] == root_Data)
        {
            root_Inorder_Index = i;
            break;
        }
    }

    int Left_Inorder_start = inS;
    int Left_Inorder_end = root_Inorder_Index - 1;
    int Right_Inorder_start = root_Inorder_Index + 1;
    int Right_Inorder_end = inE;

    int Left_Preorder_start = preS + 1;
    int Left_Preorder_end = Left_Preorder_start + Left_Inorder_end - Left_Inorder_start;
    int Right_Preorder_start = Left_Preorder_end + 1;
    int Right_Preorder_end = preE;

    TreeNode *root = new TreeNode(root_Data);
    root->left = Build_Tree_Helper(pre, ino, Left_Preorder_start, Left_Preorder_end, Left_Inorder_start, Left_Inorder_end);
    root->right = Build_Tree_Helper(pre, ino, Right_Preorder_start, Right_Preorder_end, Right_Inorder_start, Right_Inorder_end);
    return root;
}
TreeNode *BuildTree(vector<int> &pre, vector<int> &ino)
{
    TreeNode *root = Build_Tree_Helper(pre, ino, 0, pre.size() - 1, 0, ino.size() - 1);
    return root;
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
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    vector<int> pre(n), in(n);
    cout << "\nEnter the PreOrder of binary Tree: ";
    for (auto &it : pre)
        cin >> it;
    cout << "\nEnter the InOrder of binary Tree: ";
    for (auto &it : in)
        cin >> it;
    TreeNode *root = BuildTree(pre, in);
    cout << "The Level Order Traversal of tree is:\n";
    bfs(root);
}

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
TreeNode *Build_Tree_Helper(vector<int> &post, vector<int> &ino, int postS, int postE, int inS, int inE)
{

    if (postS > postE || inS > inE)
        return NULL;

    int root_Data = post[postE];
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

    int Left_Postorder_start = postS;
    int Left_Postorder_end = Left_Postorder_start + Left_Inorder_end - Left_Inorder_start;
    int Right_Postorder_start = Left_Postorder_end + 1;
    int Right_Postorder_end = postE - 1;

    TreeNode *root = new TreeNode(root_Data);
    root->left = Build_Tree_Helper(post, ino, Left_Postorder_start, Left_Postorder_end, Left_Inorder_start, Left_Inorder_end);
    root->right = Build_Tree_Helper(post, ino, Right_Postorder_start, Right_Postorder_end, Right_Inorder_start, Right_Inorder_end);
    return root;
}
TreeNode *BuildTree(vector<int> &post, vector<int> &ino)
{
    TreeNode *root = Build_Tree_Helper(post, ino, 0, post.size() - 1, 0, ino.size() - 1);
    return root;
}
void preOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
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
    vector<int> post(n), in(n);
    cout << "\nEnter the PostOrder of binary Tree: ";
    for (auto &it : post)
        cin >> it;
    cout << "\nEnter the InOrder of binary Tree: ";
    for (auto &it : in)
        cin >> it;
    TreeNode *root = BuildTree(post, in);
    cout << "The Level Order Traversal of tree is:\n";
    bfs(root);
    cout << "The PreOrder will be :\n";
    preOrder(root);
}

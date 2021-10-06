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
void treeHelper(TreeNode *root, int l, int h, vector<int> &v)
{
    if (root == NULL)
        return;
    if (root->val > l && root->val > h)
        treeHelper(root->left, l, h, v); // iske right main toh jaaenge ni bcz root->data hi l, h se bada hai toh iske right wale bhi l,h se bde honge
    else if (root->val < l && root->val < h)
        treeHelper(root->right, l, h, v);// iske left main toh jaaenge ni bcz root->data hi l, h se chota hai toh iske left wale bhi l,h se chote honge
    else
    {
      // ab root->data range main hai, 
      // toh iske left and right dono main jaaenge, 
      // ab wo apni iccha hai inorder / post/ pre kis order main print krna hai in values ko jo range main hain.
        treeHelper(root->left, l, h, v);
        v.push_back(root->val);
        treeHelper(root->right, l, h, v);
    }
}
vector<int> printInRange(TreeNode *root, int low, int high)
{
    vector<int> v;
    treeHelper(root, low, high, v);
    return v;
}
int main()
{
    TreeNode *root = BuildTree();
    cout << "The inorder of Tree is : ";
    print(root);
    cout << "\nThe level order traversal will be : \n";
    bfs(root);
    int l, h;
    cout << "Enter the lower range : ";
    cin >> l;
    cout << "Enter the upper range : ";
    cin >> h;
    cout << "Elements in range : ";
    vector<int> v = printInRange(root, l, h);
    for (auto it : v)
        cout << it << " ";
}

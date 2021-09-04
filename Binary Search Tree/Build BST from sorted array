#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode *buildTreeFromSortedArray(vector<int> &v, int s, int e)
{
    if (s > e)
        return NULL;
    int mid = (s + e) / 2;
    TreeNode *root = new TreeNode(v[mid]);
    root->left = buildTreeFromSortedArray(v, s, mid - 1);
    root->right = buildTreeFromSortedArray(v, mid + 1, e);
    return root;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> v(n);
        for (auto &it : v)
            cin >> it;
        TreeNode *root = buildTreeFromSortedArray(v, 0, v.size() - 1);
        print(root);
        v.clear();
        cout << endl;
    }
}

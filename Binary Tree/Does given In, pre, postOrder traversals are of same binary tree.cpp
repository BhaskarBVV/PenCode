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
bool chk(int in[], int pre[], int post[], int inS, int inE, int preS, int preE, int postS, int postE)
{
    if (inS > inE && preS > preE && postS > postE)
    {
        // cout << "B";
        return true;
    }
    if (inS > inE || preS > preE || postS > postE)
    {
        // cout << "C";
        return false;
    }
    if (pre[preS] != post[postE])
    {
        // cout << "D";
        return false;
    }
    int root = pre[preS];
    int flag = 1;
    int i;
    // cout << pre[preS] << endl;
    for (i = inS; i <= inE; i++)
    {
        if (in[i] == root)
        {
            // cout << "found";
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        // cout << "A";
        return false;
    } //root was not present in inorder.
    int left_inS = inS;
    int left_inE = i - 1;
    int right_inS = i + 1;
    int right_inE = inE;

    int tot = left_inE - left_inS;

    int left_preS = preS + 1;
    // if (left_preS + tot > preE)
    //     return false;
    int left_preE = left_preS + tot;
    // if (left_preE + 1 > preE)
    //     return false;
    int right_preS = left_preE + 1;
    int right_preE = preE;

    int left_postS = postS;
    // if (left_postS + tot > postE)
    //     return false;
    int left_postE = left_postS + tot;
    // if (left_postE + 1 > postE)
    //     return false;
    int right_postS = left_postE + 1;
    int right_postE = postE - 1;

    bool left_subtree = chk(in, pre, post, left_inS, left_inE, left_preS, left_preE, left_postS, left_postE);
    bool right_subtree = chk(in, pre, post, right_inS, right_inE, right_preS, right_preE, right_postS, right_postE);
    return left_subtree && right_subtree;
}
int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the Inorder : ";
    int in[n];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    cout << "Enter the PreOrder : ";
    int pre[n];
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    cout << "Enter the Postorder : ";
    int post[n];
    for (int i = 0; i < n; i++)
        cin >> post[i];
    cout << chk(in, pre, post, 0, n - 1, 0, n - 1, 0, n - 1);
}

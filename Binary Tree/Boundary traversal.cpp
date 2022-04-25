struct Node
{
    int data;
    Node *left, *right;
};
//----------------------------------------------------------------------------------------------------------------
void call_left(vector<int> &v, Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    v.push_back(root->data);
    if (root->left)
        call_left(v, root->left);
    else
        call_left(v, root->right);
}
//----------------------------------------------------------------------------------------------------------------
void call_leaves(vector<int> &v, Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(root->data);
    }
    call_leaves(v, root->left);
    call_leaves(v, root->right);
}
//----------------------------------------------------------------------------------------------------------------
void call_right(stack<int> &s, Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    s.push(root->data);
    if (root->right != NULL)
        call_right(s, root->right);
    else
        call_right(s, root->left);
}
//----------------------------------------------------------------------------------------------------------------
vector<int> boundary(Node *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    // if root != leaf, than only push root node in beginning.
    // bcz leaf nodes will be called by call_leaves and there the root node which is leaf can be pushed.
    if (root->left != NULL || root->right != NULL)
        ans.push_back(root->data);
    // left + leaves + revserse(right)
    call_left(ans, root->left);
    call_leaves(ans, root);
    stack<int> s;
    call_right(s, root->right);
    int temp;
    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        ans.push_back(temp);
    }
    return ans;
}

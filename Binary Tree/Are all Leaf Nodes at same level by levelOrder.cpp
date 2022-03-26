struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
bool check(Node *root)
{
    if (root == NULL)
        return true;
    queue<pair<int, Node *>> q;
    int leafLvl = INT_MIN;
    q.push({0, root});
    pair<int, Node *> temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp.second->left == NULL && temp.second->right == NULL)
        {
            if (leafLvl == INT_MIN) // pehli baar level pata kr lenge kisi ek leaf ka
                leafLvl = temp.first;
            else
            {
                if (leafLvl != temp.first)  // isse sabhi leaves ke level ko check krenge.
                    return false;
            }
        }
        if (temp.second->left)
            q.push({temp.first + 1, temp.second->left});
        if (temp.second->right)
            q.push({temp.first + 1, temp.second->right});
    }
    return true;
}

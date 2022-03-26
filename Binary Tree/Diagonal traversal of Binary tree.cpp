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
vector<vector<int>> diagonal(Node *root)
{
    if (root == NULL)
        return {};
    queue<Node *> q;
    Node *temp;
    q.push(root);
    // loop from 1 -> current size of queue(i.e., loop over every component of I-th diagonal).
    // (har node ke right main chalte chalo jab tak uska right null na ho jaye, aur har node ke left ko queue main daalte chalo, taki next diagonal prepare ho jaye)
    // jo left nodes daale thae queue main, wo components hain, jinki help se next diagonals print honge.
    vector<vector<int>> allDiagonals;
    while (!q.empty())
    {
        vector<int> Currdiagonal;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            temp = q.front();
            q.pop();
            while (temp != NULL)
            {
                if (temp->left)
                    q.push(temp->left);
                Currdiagonal.push_back(temp->data);
                temp = temp->right; // har node ke right main chalte chalo, jab tak wo null na ho jaye
            }
        }
        allDiagonals.push_back(Currdiagonal);
    }
    return allDiagonals;
}

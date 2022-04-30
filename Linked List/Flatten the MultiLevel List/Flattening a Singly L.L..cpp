// The flattened list will be printed using the bottom pointer instead of next pointer.
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1/

void dfs(multiset<int> &s, Node *root)
{
    if (root == NULL)
        return;
    while (root != NULL)
    {
        s.insert(root->data);
        Node *nextNode = root->next;
        dfs(s, root->bottom);
        root = nextNode;
    }
}
Node *flatten(Node *root)
{
    if (root == NULL)
        return NULL;
    multiset<int> s;
    dfs(s, root);
    Node *head = new Node(-1);
    Node *temp = head;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        
        temp->bottom = new Node(*it);
        temp=temp->bottom;
        
    }
    return head->bottom;
}

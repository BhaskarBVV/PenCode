Node *bTreeToCList(Node *root)
{
    Node *head = NULL, *tail = NULL;

    helper(root, head, tail);

    head->left = tail;
    tail->right = head;

    return head;
}
void helper(Node *root, Node *&head, Node *&tail)
{
    if (root == NULL)
        return;

    helper(root->left, head, tail);

    //Extract the address of right child of current node, bcz 
    // we are breaking the connections of root, while adding it to the CDLL.
    Node *RootRight = root->right;
    
    if (head == NULL)
    {
        head = tail = root;
    }
    else
    {
        // Free the root.
        root->left = NULL;
        root->right = NULL;

        //Add the current root to the CDLL.
        tail->right = root;
        root->left = tail;
        
        //move tail ahead.
        tail = root;
    }
    helper(RootRight, head, tail);
}

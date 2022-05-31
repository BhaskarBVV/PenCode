class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;

        Node *cur, *head, *tail;
        cur = root;
        head = tail = NULL;

        while (cur != NULL) // for moving downward
        {
            while (cur != NULL) // for moving in same level
            {
                // checking for left.
                if (cur->left != NULL)
                {
                    if (head == NULL)
                    {
                        head = cur->left;
                        tail = cur->left;
                    }
                    else
                    {
                        tail->next = cur->left;
                        tail = tail->next;
                    }
                }

                //checking for right.
                if (cur->right != NULL)
                {
                    if (head == NULL)
                    {
                        head = cur->right;
                        tail = cur->right;
                    }
                    else
                    {
                        tail->next = cur->right;
                        tail = tail->next;
                    }
                }
                cur = cur->next;
            }

            // initializing for next level.
            cur = head;
            head = NULL;
            tail = NULL;
            
        }
        return root;
    }
};

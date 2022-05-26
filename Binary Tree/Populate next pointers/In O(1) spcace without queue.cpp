// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *p1 = root, *p2;
        while (p1 != NULL)
        {
            p2 = p1;

            while (p2 != NULL)
            {
                if (p2->left)
                    p2->left->next = p2->right;

                if (p2->next && p2->right)
                    p2->right->next = p2->next->left;

                p2 = p2->next;
            }

            p1 = p1->left;
        }
        return root;
    }
};

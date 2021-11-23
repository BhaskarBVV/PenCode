struct Node* reverseList(struct Node *head)
    {
        Node* newhead=NULL, *temp;
        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            temp->next=newhead;
            newhead=temp;
        }
        return newhead;
    }

// create a newhead pointer with null value and rearrange the given linked list by adding each of its node at the beginnning of newhead list, until given list gets empty.
// No extra memory will be needed because we are just changing the links of existing nodes.

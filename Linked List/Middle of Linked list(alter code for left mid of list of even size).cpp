Node* getMid(Node* head)
{
    Node* slow=head, *fast=head;
    while(fast->next!=NULL && fast->next->next != NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

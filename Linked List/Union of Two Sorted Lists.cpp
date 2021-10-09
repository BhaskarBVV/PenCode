struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    Node* head=new Node(-1), *a1=head1, *a2=head2, *h=head;
    int x=INT_MIN;
    while (a1!= NULL && a2!=NULL)
    {
        if (a1->data == a2->data && a1->data != x)
        {
            x = a1->data;
            h->next=new Node(a1->data);
            h=h->next;
            a1=a1->next;
            a2=a2->next;
        }
        else if (a1->data == a2->data && a1->data == x)
        {
            a1=a1->next;
            a2=a2->next;
        }
        else if (a1->data < a2->data && a1->data != x)
        {
            x = a1->data;
            h->next=new Node(a1->data);
            h=h->next;
            a1=a1->next;
        }
        else if (a1->data < a2->data && a1->data == x)
        {
            a1=a1->next;
        }
        else if (a1->data > a2->data && a2->data != x)
        {
            x = a2->data;
            h->next=new Node(a2->data);
            h=h->next;
            a2=a2->next;
        }
        else if (a1->data > a2->data && a2->data == x)
            a2=a2->next;
    }
    // now merging leftover arrays
    while (a1!=NULL)
    {
        if (a1->data != x)
        {
            x = a1->data;
            h->next=new Node(a1->data);
            h=h->next;
            a1=a1->next;
        }
        else
            a1=a1->next;
    }
    while (a2!=NULL)
    {
        if (a2->data != x)
        {
            x = a2->data;
            h->next=new Node(a2->data);
            h=h->next;
            a2=a2->next;
        }
        else
            a2=a2->next;
    }
    head=head->next;
    return head;
}

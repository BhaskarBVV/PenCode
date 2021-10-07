//  The original relative order of the nodes in each of the three partitions should be preserved. 
 
 struct Node* partition(struct Node* head, int x) 
{
    Node* small=new Node(-1);
    Node* large = new Node(-1);
    Node* val = new Node(-1);
    Node*temp=head, *s=small, *l=large, *v=val;
    while(temp!=NULL)
    {
        if(temp->data > x)
        {
            l->next=temp;
            l=temp;
        }
        else if(temp->data==x)
        {
            v->next=temp;
            v=temp;
        }
        else
        {
            s->next=temp;
            s=temp;
        }
        temp=temp->next;
    }
    small=small->next;
    val=val->next;
    large=large->next;
    if(small)
    {
        if(val)
        {
            s->next=val;
            if(large)
            {
                v->next=large;
                l->next=NULL;
                return small;
            }
            else
            {
                v->next=NULL;
                return small;
            }
        }
        else if(large)
        {
            s->next=large;
            l->next=NULL;
            return small;
        }
    }
    else if(val)
    {
        if(large)
        {
            v->next=large;
            l->next=NULL;
            return val;
        }
        else
        {
            v->next=NULL;
            return val;
        }
    }
    else if(large)
    {
        l->next=NULL;
        return large;
    }
    return NULL;
}

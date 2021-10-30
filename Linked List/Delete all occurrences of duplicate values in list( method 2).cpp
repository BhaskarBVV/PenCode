// Input: 
// N = 8
// Linked List = 23->28->28->35->49->49->53->53
// Output: 
// 23 35
// Explanation:
// The duplicate numbers are 28, 49 and 53 which are removed from the list.

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp=head, *ptemp=NULL;
        while(temp!=NULL)
        {
            if(temp->next!=NULL && temp->next->val!=temp->val)
            {ptemp=temp;
                temp=temp->next;}
            else if(temp->next!=NULL && temp->next->val == temp->val)
            {
                int x=temp->val;
                if(head==temp)
                {
                    while(temp!= NULL && temp->val == x)
                        temp=temp->next;
                    head=temp;
                    ptemp=NULL;
                }
                else
                {
                    while(temp!=NULL && temp->val==x)
                        temp=temp->next;
                    ptemp->next=temp;
                }   
            }
            else if(temp->next==NULL)
                temp=temp->next;
        }
        return head;
    }
};

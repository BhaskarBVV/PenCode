// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode*temp1, *temp2, *head=0, *temp, *newnode;
        temp1=l1;
        temp2=l2;
        int x,y=0;
        while(temp1!=0 && temp2!=0)
        {
            x=temp1->val + temp2->val + y;
            y=x/10;
            
            newnode=new ListNode(x%10);
            if(head==0)
            {head=newnode; temp=newnode;}
            else 
            {temp->next=newnode; temp=newnode;}
            
            
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=0)
        {
            x=temp1->val + y;
            y=x/10;
            newnode=new ListNode(x%10);
            if(head==0)  // could have taken a dummy node and then there would be no need to check the head==0 again and again, and at end return dummy->next.
            {head=newnode; temp=newnode;}
            else 
            {temp->next=newnode; temp=newnode;}
            temp1=temp1->next;
        }
        while(temp2!=0)
        {
            x=temp2->val + y;
            y=x/10;
            newnode=new ListNode(x%10);
            if(head==0)
            {head=newnode; temp=newnode;}
            else 
            {temp->next=newnode; temp=newnode;}
            temp2=temp2->next;
        }
        while(y!=0)
        {
            x=y%10;
            y=y/10;
            newnode=new ListNode(x%10);
            if(head==0)
            {head=newnode; temp=newnode;}
            else 
            {temp->next=newnode; temp=newnode;}
        }
        return head;
    }
};

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
class Solution {
public:
    ListNode* add_carry(ListNode* l, int c)
    {
        if(l==NULL && c==0)
            return NULL;
        if(l!=NULL && c==0)
            return l;
        if(l==NULL && c!=0)
            return new ListNode (c);
        int sum=l->val+c;
        ListNode* node=new ListNode(sum%10);
        node->next=add_carry(l->next,sum/10);
        return node;
            
    }
    ListNode* listHelper(ListNode* l1, ListNode* l2,int c)
    {
        
        if(l1==0 && l2==0)
        {
            if(c==0)
                return NULL;
            else if(c!=0)
                return new ListNode(c);
        }
        if(l1==0 && c==0)
            return l2;
        if(l1==0 && c!=0)
            return add_carry(l2,c);
        if(l2==0 && c==0)
            return l1;
        if(l2==0 && c!=0)
            return add_carry(l1,c);
        // cout<<c<<" "<<l1->val<<" "<<l2->val<<endl;
        int sum=l1->val + l2->val + c;
        ListNode* node=new ListNode(sum%10);
        node->next=listHelper(l1->next,l2->next,sum/10);
        return node;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry=0;
        return listHelper(l1,l2,carry);
    }
};


class Solution {
public:
    void ListHelper(ListNode* &l, ListNode* r, int &cnt, int k)
    {
        if(r->next!=NULL)
            ListHelper(l,r->next,cnt,k);
        cnt+=1;
        if(cnt==k)
            swap(r->val, l->val);
        l=l->next;
        
    }
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* right=head, * left=head;
        int cnt=0;
        ListHelper(left,right,cnt,k);
        return head;
    }
};

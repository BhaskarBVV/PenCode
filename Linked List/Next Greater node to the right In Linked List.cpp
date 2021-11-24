// Input: head = [2,7,4,3,5]
// Output: [7,0,5,5,0]

// Input: head = [2,1,5]
// Output: [5,5,0]


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
    void treeHelper(ListNode* root, stack<int>&s)
    {
        if(root==NULL)
            return;
        treeHelper(root->next,s);
        if(s.empty())
        {
            // cout<<"A"<<" "<<root->val;
            s.push(root->val);
            root->val=0;
        }
        else if (root->val < s.top())
        {
            int x=root->val;
            root->val = s.top();
            s.push(x);
        }
        else
        {
            while (!s.empty() && root->val >=s.top())
            {
                s.pop();
            }
            int x=root->val;
            if (s.empty())
                root->val=0;
            else
                root->val=s.top();
            s.push(x);
        }
        // cout<<root->val<<endl;
    }
  // start solving from right of LL.
    vector<int> nextLargerNodes(ListNode *head)
    {
        stack<int> s;
        treeHelper(head, s);
        vector<int> v;
        ListNode *temp = head;
        while (temp != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        return v;
    }
};

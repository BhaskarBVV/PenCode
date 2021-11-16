// Unlink the sublist of size k from the rest of the list, reverse it and link it again.

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

// Input: head = [1,2,3,4,5], k = 1
// Output: [1,2,3,4,5]

// Input: head = [1], k = 1
// Output: [1]

//Bhaskar Varshney
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *BuildList()
{
    ListNode *head = NULL, *temp;
    int choice = 1;
    while (choice == 1)
    {
        ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
        cout << "Enter data : ";
        cin >> newnode->val;
        newnode->next = 0;
        if (head == 0)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "Want another node to be inserted : ";
        cin >> choice;
    }
    return head;
}
void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
ListNode *rev(ListNode *head, ListNode *end)
{
    ListNode *cur = head, *prev = NULL, *nxt = head;
    while (nxt != end)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *pre_list = dummy, *post_list;
    ListNode *temp = head, *temp1 = head;

    //This pre_list and post_list belongs to nodes before and after the beginning and ending nodes of list.

    while (temp != NULL)
    {
        // cout<<temp->val<<endl;
        int cnt = 1;
        while (cnt != k && temp->next != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        // cout<<temp->val<<endl;

        if (cnt < k)
            return dummy->next;

        post_list = temp->next;

        ListNode *head_rev_list = rev(temp1, post_list);
        ListNode *tail_rev_list = head_rev_list;
        while (tail_rev_list->next != NULL)
            tail_rev_list = tail_rev_list->next;

        // cout<<"HEAD"<<head_rev_list->val<<endl;
        // cout<<"TAIL"<<tail_rev_list->val<<endl;

        //Linking the remaining list again...
        pre_list->next = head_rev_list;
        tail_rev_list->next = post_list;

        //setting pointers for next iteration....
        temp = post_list;
        temp1 = post_list;
        pre_list = tail_rev_list;
    }
    return dummy->next;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "Original List : ";
    print(head);
    cout << endl;
    int k;
    cout << "Enter the size of groups : ";
    cin >> k;
    head = reverseKGroup(head, k);
    cout << "\nThe list after reversing list of k groups : ";
    print(head);
}

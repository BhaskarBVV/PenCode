// 1->0->2->1->0->2->1
//   => 0->0->1->1->1->2->2

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

// Used three pointer with dummy values (-1), to hold address of pre-build nodes with particular values.
// In it i've broken the links of previously given linked list
// used temp pointers for all values 0,1,2 to add address of next nodes.
// used a new head poineter (newhead) to return newly transformed list.

// Maintain 3 pointers named zero, one and two to point to current ending nodes of linked lists containing 0, 1, and 2 respectively.
// For every traversed node, check the data and attach it to the end of its corresponding list.
// Finally, link all three lists.

ListNode *segregate(ListNode *head)
{
    ListNode *one = new ListNode(-1), *two = new ListNode(-1), *zero = new ListNode(-1);
    ListNode *cur = head, *nxt, *otemp = one, *ttemp = two, *ztemp = zero;
    while (cur != NULL)
    {
        if (cur->val == 0)
        {
            ztemp->next = cur;
            ztemp = ztemp->next;
            cur = cur->next;
        }
        else if (cur->val == 1)
        {
            otemp->next = cur;
            otemp = otemp->next;
            cur = cur->next;
        }
        else if (cur->val == 2)
        {
            ttemp->next = cur;
            ttemp = ttemp->next;
            cur = cur->next;
        }
    }
    zero = zero->next;
    one = one->next;
    two = two->next;
    ListNode *newhead = NULL;
    if (zero != NULL)
    {
        newhead = zero;
        if (one != NULL)
        {
            ztemp->next = one;
            if (two != NULL)
            {
                otemp->next = two;
                ttemp->next = NULL;
            }
            else
                otemp->next = NULL;
        }
        else if (two != NULL)
        {
            ztemp->next = two;
            ttemp->next = NULL;
        }
        else
            ztemp->next = NULL;
    }
    else if (one != NULL)
    {
        newhead = one;
        if (two != NULL)
        {
            otemp->next = two;
            ttemp->next = NULL;
        }
        else
            otemp->next = NULL;
    }
    else if (two != NULL)
    {
        newhead = two;
        ttemp->next = NULL;
    }
    else
        newhead = NULL;
    return newhead;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "Original list : ";
    print(head);
    head = segregate(head);
    cout << "\nList after segregating 0's, 1's, 2's : ";
    print(head);
}

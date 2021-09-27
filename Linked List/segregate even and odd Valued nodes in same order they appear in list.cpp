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

// Maintain 2 pointers named even, odd point to current linked lists containing even or odd value respectively.
// For every traversed node, check the data and attach it to the end of its corresponding list.
// Finally, link all two lists.

ListNode *divide(ListNode *head)
{
    ListNode *even = new ListNode(-1), *odd = new ListNode(-1);
    ListNode *etemp = even, *otemp = odd;
    ListNode *temp = head;
    while (temp != NULL)
    {
        if (temp->val % 2 == 0)
        {
            etemp->next = temp;
            etemp = etemp->next;
            temp = temp->next;
        }
        else if (temp->val % 2 != 0)
        {
            otemp->next = temp;
            otemp = otemp->next;
            temp = temp->next;
        }
    }
    even = even->next;
    odd = odd->next;
    ListNode *newhead = NULL;
    if (even)
    {
        newhead = even;
        if (odd)
        {
            etemp->next = odd;
            otemp->next = NULL;
        }
        else
            etemp->next = NULL;
    }
    else if (odd)
    {
        newhead = odd;
        otemp->next = NULL;
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
    head = divide(head);
    cout << "\nList after segregating even and odd nodes in the order they appear : ";
    print(head);
}

//  10->4->9->1->3->5->9->4
//  l1=10->9->3->9->NULL
//  l2=4->1->5->4->NULL
//  rev(l2)=4->5->1->4->NULL
//  add l2 at and of l1
//  =>10->9->3->9->4->5->1->4->NULL

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
ListNode *rev(ListNode *head)
{
    ListNode *cur = head, *prev = NULL, *nxt = head;
    while (nxt != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
// Created two two lists from existing list by changing the pointers.
// Stored alternate nodes in two lists, let first list as it is but reverse second list and add it at end of first list.
void rearrange(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return;
    ListNode *first = new ListNode(-1), *sec = new ListNode(-1);
    int flag = 1;
    ListNode *temp = head, *ftemp = first, *stemp = sec;
    while (temp != NULL)
    {
        if (flag == 1)
        {
            ftemp->next = temp;
            ftemp = ftemp->next;
            temp = temp->next;
            flag = 0;
        }
        else if (flag == 0)
        {
            stemp->next = temp;
            stemp = stemp->next;
            temp = temp->next;
            flag = 1;
        }
    }

    ftemp->next = NULL;
    stemp->next = NULL;

    first = first->next;
    sec = sec->next;

    sec = rev(sec);

    ftemp->next = sec;
    head = first;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "Original List : ";
    print(head);
    rearrange(head);
    cout << "\nList after rearranging : ";
    print(head);
}

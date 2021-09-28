// 2->4->6->8
// rearrange such that all the odd posotion nodes appear before the even position nodes.
// =>2->6->4->8

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

ListNode *rearrangeEvenOdd(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *odd = new ListNode(-1), *even = new ListNode(-1);
    ListNode *etemp = even, *otemp = odd;
    int flag = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        if (flag == 0)
        {
            otemp->next = temp;
            otemp = otemp->next;
            temp = temp->next;
            flag = 1;
        }
        else
        {
            etemp->next = temp;
            etemp = etemp->next;
            temp = temp->next;
            flag = 0;
        }
    }
    even = even->next;
    odd = odd->next;
    if (odd)
    {
        head = odd;
        otemp->next = even;
        etemp->next = NULL;
    }
    else
    {
        head = even;
        etemp->next = NULL;
    }
    return head;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "Original list : ";
    print(head);
    head = rearrangeEvenOdd(head);
    cout << "\nList after segregating even and odd position nodes in the order they appear : ";
    print(head);
}

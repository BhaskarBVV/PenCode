// 5->10->15->40->NULL 
// 2->3->20->NULL
// After merging : 40->20->15->10->5->3->2->NULL
// Add the newnodes in beginning instead of end at every time;

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
ListNode *insert(ListNode *head, int x)
{
    ListNode *newnode;
    newnode = (ListNode *)malloc(sizeof(ListNode));
    newnode->val = x;
    if (head == NULL)
    {
        head = newnode;
        head->next = NULL;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    return head;
}
ListNode *merge_in_des_order(ListNode *node1, ListNode *node2)
{
    ListNode *temp1 = node1, *temp2 = node2, *head = NULL, *newnode;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val <= temp2->val)
        {
            head = insert(head, temp1->val);
            temp1 = temp1->next;
        }
        else if (temp1->val > temp2->val)
        {
            head = insert(head, temp2->val);
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        head = insert(head, temp1->val);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        head = insert(head, temp2->val);
        temp2 = temp2->next;
    }
    return head;
}
int main()
{
    cout << "Build list 1 : \n";
    ListNode *head1 = BuildList();
    cout << "Original list : ";
    print(head1);

    cout << "\nBuild list 2 : \n";
    ListNode *head2 = BuildList();
    cout << "Original list : ";
    print(head2);

    ListNode *head = merge_in_des_order(head1, head2);

    cout << "\nThe list after mergering in descending order: ";
    print(head);
}

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
ListNode *findIntersection(ListNode *head1, ListNode *head2)
{
    ListNode *temp1 = head1, *temp2 = head2, *newhead = new ListNode(-1), *temp = newhead;
    ListNode *newnode;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val == temp2->val)
        {
            newnode = new ListNode(temp1->val);
            temp->next = newnode;
            temp = newnode;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->val > temp2->val)
        {
            temp2 = temp2->next;
        }
        else if (temp1->val < temp2->val)
        {
            temp1 = temp1->next;
        }
    }
    return newhead->next;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "\nOriginal List 1 : ";
    print(head);
    cout << "\nBuild list 2: \n";
    ListNode *head2 = BuildList();
    cout << "\nOriginal List 2 : ";
    print(head2);
    ListNode *newhead = findIntersection(head, head2);
    cout << "\nThe intersection part : ";
    print(newhead);
}

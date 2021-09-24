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
ListNode *reverseList(ListNode *head)
{
    ListNode *prev, *cur, *nextt;
    prev = NULL;
    cur = head;
    nextt = cur;
    while (nextt != NULL)
    {
        nextt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextt;
    }
    return prev;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "The list is : ";
    print(head);
    head = reverseList(head);
    cout << "\nThe list after reversing : ";
    print(head);
}

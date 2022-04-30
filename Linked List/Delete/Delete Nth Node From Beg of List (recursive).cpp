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
ListNode *ListHelper(ListNode *head, int x)
{
    if (head == NULL)
        return NULL;
    x -= 1;
    if (x == 1)
        head->next = head->next->next;
    head->next = ListHelper(head->next, x);
    return head;
}
ListNode *deleteNode(ListNode *head, int x)
{
    if (x == 1)
        return head->next;
    return ListHelper(head, x);
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "Original list : ";
    print(head);
    int x;
    cout << "\nEnter the nth Node from beginning to be deletd : ";
    cin >> x;
    head = deleteNode(head, x);
    cout << "\nThe list after deleting : ";
    print(head);
}

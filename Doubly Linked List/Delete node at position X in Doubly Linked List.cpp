//Bhaskar Varshney
#include <iostream>
using namespace std;
struct DblyListNode
{
    int val;
    DblyListNode *next;
    DblyListNode *prev;
    DblyListNode()
    {
        val = 0;
        next = nullptr;
        prev = nullptr;
    }
    DblyListNode(int x)
    {
        val = x;
        next = nullptr;
        prev = nullptr;
    }
};
DblyListNode *BuildList()
{
    DblyListNode *head = NULL, *tail;
    int choice = 1;
    while (choice == 1)
    {
        DblyListNode *newnode = new DblyListNode();
        cout << "Enter data : ";
        cin >> newnode->val;
        if (head == 0)
            head = tail = newnode;
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        cout << "Want another node to be inserted : ";
        cin >> choice;
    }
    return head;
}
void print(DblyListNode *head)
{
    DblyListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
DblyListNode *deleteNode(DblyListNode *head, int x)
{
    if (head == NULL)
        return NULL;
    if (x == 1)
        return head->next;
    DblyListNode *temp = head;
    x -= 1;
    while (temp != NULL)
    {
        if (x == 0)
            break;
        x -= 1;
        temp = temp->next;
    }
    if (temp->next == 0)
        temp->prev->next = NULL;
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    return head;
}
int main()
{
    cout << "Build list : \n";
    DblyListNode *head = BuildList();
    cout << "Originl list is : ";
    print(head);
    int x;
    cout << "\nEnter the position of deletion : ";
    cin >> x;
    head = deleteNode(head, x);
    cout << "\nList after deleting value : ";
    print(head);
}

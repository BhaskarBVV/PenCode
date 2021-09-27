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
DblyListNode *reverseDLL(DblyListNode *head)
{
    DblyListNode *pre = NULL, *cur = head, *nxt = head;
    while (nxt != NULL)
    {
        cur = nxt;
        nxt = cur->next;
        cur->next = pre;
        cur->prev = nxt;
        pre = cur;
    }
    return cur;
}
int main()
{
    cout << "Build list : \n";
    DblyListNode *head = BuildList();
    cout << "Originl list is : ";
    print(head);
    head = reverseDLL(head);
    cout << "\nList after reversing : ";
    print(head);
}

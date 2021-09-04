#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *sortedMerge(Node *l1, Node *l2)
{
    Node *head = 0, *temp, *newnode;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            newnode = (Node *)malloc(sizeof(Node));
            newnode->data = l1->data;
            newnode->next = NULL;
            if (head == 0)
                head = temp = newnode;
            else
            {
                temp->next = newnode;
                temp = temp->next;
            }
            l1 = l1->next;
        }
        else if (l1->data > l2->data)
        {
            newnode = (Node *)malloc(sizeof(Node));
            newnode->data = l2->data;
            newnode->next = NULL;
            if (head == 0)
                head = temp = newnode;
            else
            {
                temp->next = newnode;
                temp = temp->next;
            }
            l2 = l2->next;
        }
    }
    while (l1 != 0)
    {
        newnode = (Node *)malloc(sizeof(Node));
        newnode->data = l1->data;
        newnode->next = NULL;
        if (head == 0)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        l1 = l1->next;
    }
    while (l2 != 0)
    {
        newnode = (Node *)malloc(sizeof(Node));
        newnode->data = l2->data;
        newnode->next = NULL;
        if (head == 0)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        l2 = l2->next;
    }
    return head;
}
void printList(struct Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
Node *createList(int n)
{
    Node *dummy = new Node(-1);
    Node *head = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        head->next = new Node(val);
        head = head->next;
    }
    return dummy->next;
}
int main()
{
    int n;
    cout << "Enter the size of first Linked List ";
    cin >> n;
    cout << "Enter First Sorted List : \n";
    Node *h1 = createList(n);
    cout << "Enter the size of second Linked List ";
    cin >> n;
    cout << "Enter Second Sorted List : \n";
    Node *h2 = createList(n);
    Node *head = sortedMerge(h1, h2);
    printList(head);
}

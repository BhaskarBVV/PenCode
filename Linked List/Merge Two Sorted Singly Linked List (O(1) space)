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
    if (l1 == 0)
        return l2;
    else if (l2 == 0)
        return l1;
    Node *c;
    if (l1->data < l2->data)
    {
        c = l1;
        c->next = sortedMerge(l1->next, l2);
    }
    else
    {
        c = l2;
        c->next = sortedMerge(l1, l2->next);
    }
    return c;
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

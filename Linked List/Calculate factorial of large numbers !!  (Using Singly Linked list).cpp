#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *add(struct node *tail, int c)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = c;
    newnode->next = 0;
    tail->next = newnode;
    tail = newnode;
    return tail;
}
//Using recursion to print the list in reverse order...
void print(struct node *head)
{
    if (head == 0)
        return;
    print(head->next);
    cout << head->data;
}
int main()
{
    struct node *head = 0, *temp, *newnode, *tail;
    int n, c, i, x;
    cout << "Enter the number: ";
    cin >> n;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = 0;
    newnode->data = 1;
    //head=0 initially
    head = newnode;
    tail = newnode;

    for (i = 2; i <= n; i++)
    {
        c = 0;
        for (temp = head; temp != 0; temp = temp->next)
        {
            x = (temp->data * i) + c;
            temp->data = x % 10;
            c = x / 10;
        }
        while (c != 0)
        {
            tail = add(tail, c % 10);
            c /= 10;
        }
    }
    print(head);
}

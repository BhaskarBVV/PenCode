#include <iostream>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(nullptr) {}
};
ListNode *BuildList()
{
    ListNode *head = NULL, *temp;
    int choice = 1;
    while (choice == 1)
    {
        ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
        cout << "Enter data : ";
        cin >> newnode->data;
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
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL)
        return head;
    ListNode *temp = head;
    int cnt = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    cout << cnt;
    temp->next = head;
    ListNode *temp2 = head;
    k = k % cnt;
    cnt = cnt - k;
    while (cnt != 1)
    {
        temp2 = temp2->next;
        cnt -= 1;
    }
    head = temp2->next;
    temp2->next = 0;
    return head;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    int x;
    cout << "\nEnter the number of rotations : ";
    cin >> x;
    head = rotateRight(head, x);
    cout << "\nNew list after rotations : ";
    ListNode *temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

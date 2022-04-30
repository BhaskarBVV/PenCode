//Bhaskar Varshney
#include <iostream>
#include <set>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
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
void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
ListNode *findIntersection(ListNode *head1, ListNode *head2)
{
    ListNode *temp2 = head2;
    set<int> s;
    while (temp2 != NULL)
    {
        s.insert(temp2->data);
        temp2 = temp2->next;
    }
    ListNode *temp1 = head1, *newhead = new ListNode(-1), *ntemp = newhead, *newnode = NULL;
    while (temp1 != NULL)
    {
        if (s.find(temp1->data) != s.end())
        {
            newnode = new ListNode(temp1->data);
            ntemp->next = newnode;
            ntemp = newnode;
        }
        temp1 = temp1->next;
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

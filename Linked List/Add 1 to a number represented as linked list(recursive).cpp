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
void listHelper(ListNode *head, int &x)
{
    if (head == NULL)
        return;
    listHelper(head->next, x);
    int sum = head->val + x;
    head->val = sum % 10;
    x = sum / 10;
}
ListNode *addOne(ListNode *head)
{
    int x = 1;
    listHelper(head, x);
    if (x != 0)
    {
        ListNode *temp = new ListNode(x);
        temp->next = head;
        return temp;
    }
    return head;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "Original list : ";
    print(head);
    head = addOne(head);
    cout << "\nList after adding 1 : ";
    print(head);
}

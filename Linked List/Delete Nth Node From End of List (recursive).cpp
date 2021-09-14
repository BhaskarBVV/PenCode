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
ListNode *removeNthFromEnd(ListNode *head, int pos, int &cnt)
{
    if (head == NULL)
        return NULL;
    head->next = removeNthFromEnd(head->next, pos, cnt);
    cnt += 1;
    if (pos == cnt)
        return head->next;
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
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    int pos;
    cout << "\nEnter the n-th node from end to be deleted : ";
    cin >> pos;
    int cnt = 0;
    head = removeNthFromEnd(head, pos, cnt);
    cout << "\nThe List after removig n-th node from end : ";
    print(head);
}

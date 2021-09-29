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
    temp->next = head;
    return head;
}
void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp->next != head)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << temp->val << " ";
}
ListNode *get_mid(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast->next != head && fast->next->next != head)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
void splitList(ListNode *head, ListNode **head1_ref, ListNode **head2_ref)
{
    if (head == NULL || head->next == NULL)
        return;
    ListNode *mid = get_mid(head);
    *head1_ref = head;
    *head2_ref = mid->next;
    ListNode *temp = mid->next;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = mid->next;
    mid->next = head;
}

int main()
{
    cout << "Build circular list : \n";
    ListNode *head = BuildList();
    cout << "Original list : ";
    print(head);
    cout << "\nAfter splitting circular list into two : ";
    ListNode *head1 = NULL, *head2 = NULL;
    splitList(head, &head1, &head2);
    cout << "\nFirst half circular list : ";
    print(head1);
    cout << "\nSecond half circular list : ";
    print(head2);
}

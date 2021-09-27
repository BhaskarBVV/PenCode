// 1->2->3->4->5
// =>>  1->5->2->4->3

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
// Used crossed flag to prevent the changing of values of next pointers after we've changed the connections of half list.
// Every time the list will be broken from middle node.
// Crossed will be 0 until we've reached to end of list by recursion,
// 1 while coming back and 2 when we've crossed middle node.
// used 3 stages for crossed bcz middle node will come while going from head to NULL and also from NULL to head(while condition checking in recursion)

//connections will be changed until mid of list.

void reorder(ListNode *right, ListNode *mid, ListNode *&left, int &crossed)
{
    if (right == NULL)
    {
        crossed = 1;
        return;
    }
    reorder(right->next, mid, left, crossed);
    if (crossed == 2)
    {
        // crossed mid node and hence no changing in connections of list.
        return;
    }
    else if (crossed == 1 && right == mid)
    {
        // at mid break loop.
        right->next = NULL;
        crossed = 2;
    }
    else
    {
        ListNode *temp = left->next;
        left->next = right;
        right->next = temp;
        left = temp;
        return;
    }
}
ListNode *midList(ListNode *head)
{
    ListNode *fast = head, *slow = fast;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
void reorderList(ListNode *head)
{
    ListNode *left = head;
    int crossed = 0;
    ListNode *mid = midList(head);
    reorder(head, mid, left, crossed);
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "orginal list : ";
    print(head);
    reorderList(head);
    cout << "\nList after reorder : ";
    print(head);
}

// Input: 1 -> -2 -> -3 -> 4 -> -5
// Output: -5 -> -3 -> -2 -> 1 -> 4
  
// An important observation is, all negative elements are present in reverse order. 
// So we traverse the list, whenever we find an element that is out of order, we move it to the front of the linked list. 

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
void sortList(ListNode **head)
{
    ListNode *temp = (*head), *prev;
    while (temp != NULL)
    {
        if (temp->val < 0 && temp != (*head))
        {
            prev->next = temp->next;
            temp->next = (*head);
            (*head) = temp;
            temp = prev->next;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    ListNode **head2 = &head;
    cout << "Original List : ";
    print(head);
    sortList(head2);
    head = *head2;
    cout << "\nList after sorting the values : ";
    print(head);
}

// Input: 
// N = 8
// Linked List = 23->28->28->35->49->49->53->53
// Output: 
// 23 35
// Explanation:
// The duplicate numbers are 28, 49 and 53 which are removed from the list.
  
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
ListNode *removeAllDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    bool dup = false;
    ListNode *temp = head, *ptemp = NULL;
    while (temp != NULL)
    {
        if (temp->next != NULL && temp->val == temp->next->val)
        {
            dup = true;
            temp->next = temp->next->next;
        }
        else if (dup == true)
        {
            if (ptemp == NULL)
            {
                head = temp->next;
                temp = head;
                dup = false;
            }
            else if (ptemp != NULL)
            {
                ptemp->next = temp->next;
                temp = ptemp;
                dup = false;
            }
        }
        else
        {
            ptemp = temp;
            temp = temp->next;
        }
    }
    if (dup == true)
    {
        if (ptemp = NULL)
        {
            head = temp->next;
            temp = head;
            dup = false;
        }
        else if (ptemp != NULL)
        {
            ptemp->next = temp->next;
            temp = ptemp->next;
            dup = false;
        }
    }
    return head;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "Original List : ";
    print(head);
    head = removeAllDuplicates(head);
    cout << "\nList after removing all occurences of duplicate values : ";
    print(head);
}

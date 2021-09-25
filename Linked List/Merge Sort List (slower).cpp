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
ListNode *midNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *head = 0, *newnode, *temp;
    while (l1 != 0 && l2 != 0)
    {
        if (l1->val <= l2->val)
        {
            newnode = new ListNode(l1->val);
            if (head == 0)
                head = temp = newnode;
            else
            {
                temp->next = newnode;
                temp = temp->next;
            }
            l1 = l1->next;
        }
        else if (l1->val > l2->val)
        {
            newnode = new ListNode(l2->val);
            if (head == 0)
                head = temp = newnode;
            else
            {
                temp->next = newnode;
                temp = temp->next;
            }
            l2 = l2->next;
        }
    }
    while (l1 != 0)
    {
        newnode = new ListNode(l1->val);
        if (head == 0)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        l1 = l1->next;
    }
    while (l2 != 0)
    {
        newnode = new ListNode(l2->val);
        if (head == 0)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        l2 = l2->next;
    }
    return head;
}

ListNode *mergeSort(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *mid = midNode(head);

    ListNode *a = head;
    ListNode *b = mid->next;
    mid->next = nullptr;

    a = mergeSort(a);
    b = mergeSort(b);

    ListNode *c = merge(a, b);

    return c;
}

ListNode *sortList(ListNode *head)
{
    if (head == 0 or head->next == 0)
        return head;
    ListNode *h1 = mergeSort(head);
    return h1;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "Original list : ";
    print(head);
    head = sortList(head);
    cout << "\nList after sorting : ";
    print(head);
}

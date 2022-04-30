//Bhaskar Varshney
// This is faster because here same list's links are broken and joined into new list instead of forming entire new list with new nodes, also merge technique is different.
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
    if (l1 == nullptr || l2 == nullptr)
        return l1 != nullptr ? l1 : l2;

    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;

    ListNode *c1 = l1;
    ListNode *c2 = l2;

    while (c1 != nullptr && c2 != nullptr)
    {
        if (c1->val <= c2->val)
        {
            prev->next = c1;
            c1 = c1->next;
        }
        else
        {
            prev->next = c2;
            c2 = c2->next;
        }

        prev = prev->next;
    }

    prev->next = c1 != nullptr ? c1 : c2;

    ListNode *h = dummy->next;
    dummy->next = nullptr;
    delete dummy;
    return h;
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

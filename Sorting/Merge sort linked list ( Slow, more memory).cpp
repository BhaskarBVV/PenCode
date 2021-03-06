//This approach is bit slower and memory consuming
//because of its merging function part.
//each time while merging a new list is created,
//that occupies more memory.
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};
void printList(ListNode *head)
{
    while (head != 0)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
ListNode *midNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != 0 && fast->next->next != 0)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode *merge(ListNode *l1, ListNode *l2)
{
    cout << "l1 ";
    printList(l1);
    cout << "l2 ";
    printList(l2);
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
    cout << "After merging : ";
    printList(head);
    cout << endl
         << endl;
    return head;
}

ListNode *mergeSort(ListNode *head)
{
    if (head == 0 || head->next == 0)
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
    mergeSort(head);
    return head;
}
ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int main()
{
    int n;
    cin >> n;
    ListNode *h1 = createList(n);
    cout << endl
         << endl
         << endl;
    ListNode *head = mergeSort(h1);
    printList(head);

    return 0;
}

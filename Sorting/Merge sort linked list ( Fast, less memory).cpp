// This approach is faster
//because in its merging part same lists are altered,
//by changing the address of the remaining lists.

#include <iostream>
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

ListNode *midNode(ListNode *head)
{
    if (head == 0 || head->next == 0)
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
    if (l1 == 0 || l2 == 0)
        return l1 != 0 ? l1 : l2;

    ListNode *dummy = new ListNode(-1);
    ListNode *head = dummy;

    ListNode *c1 = l1;
    ListNode *c2 = l2;

    while (c1 != 0 && c2 != 0)
    {
        if (c1->val <= c2->val)
        {
            head->next = c1;
            c1 = c1->next;
        }
        else
        {
            head->next = c2;
            c2 = c2->next;
        }

        head = head->next;
    }

    head->next = c1 != nullptr ? c1 : c2;

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
    ListNode *nHead = mid->next;
    mid->next = nullptr;

    return merge(mergeSort(head), mergeSort(nHead));

    // or try this similar approach below
    // ListNode *mid = midNode(head);

    // ListNode *a = head;
    // ListNode *b = mid->next;
    // mid->next = nullptr;

    // a = mergeSort(a);
    // b = mergeSort(b);

    // ListNode *c = merge(a, b);

    // return c;
}

void printList(ListNode *node)
{
    ListNode *temp = node;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *head = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        head->next = new ListNode(val);
        head = head->next;
    }
    return dummy->next;
}

int main()
{
    int n;
    cin >> n;
    ListNode *h1 = createList(n);

    ListNode *head = mergeSort(h1);
    printList(head);

    return 0;
}

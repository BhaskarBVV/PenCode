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
ListNode *rotate(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    int cnt = 1;
    ListNode *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
        cnt++;
    }
    tail->next = head;
    k = k % cnt;
    cnt = 0;
    ListNode *temp = head;
    while (temp != tail && cnt != k - 1)
    {
        temp = temp->next;
        cnt++;
    }
    ListNode *t = temp->next;
    temp->next = NULL;
    return t;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "Original list : ";
    print(head);
    int x;
    cout << "\nEnter the no. of roatations to left : ";
    cin >> x;
    head = rotate(head, x);
    print(head);
}

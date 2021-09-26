//Bhaskar Varshney
#include <iostream>
#include <set>
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
int countPairs(ListNode *head1, ListNode *head2, int x)
{
    set<int> s;
    int y;
    ListNode *temp = head1;
    while (temp != NULL)
    {
        s.insert(temp->val);
        temp = temp->next;
    }
    temp = head2;
    int cnt = 0;
    while (temp != NULL)
    {
        y = x - temp->val;
        if (s.find(y) != s.end())
            cnt++;
        temp = temp->next;
    }
    return cnt;
}
int main()
{
    cout << "Build list 1 : \n";
    ListNode *head1 = BuildList();
    cout << "Original list : ";
    print(head1);

    cout << "\nBuild list 2 : \n";
    ListNode *head2 = BuildList();
    cout << "Original list : ";
    print(head2);

    int x;
    cout << "\nEnter the sum that pairs should have : ";
    cin >> x;
    cout << "Total pairs with sum x are : " << countPairs(head1, head2, x);
}

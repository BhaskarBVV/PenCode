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
void sumOfLastN_Nodes(ListNode *head, int &n, int &sum)
{
    if (head == NULL)
        return;
    sumOfLastN_Nodes(head->next, n, sum);
    n -= 1;
    if (n >= 0)
        sum += head->val;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    int n;
    cout << "Enter the N-th node from end : ";
    cin >> n;
    int sum = 0;
    sumOfLastN_Nodes(head, n, sum);
    cout << "The sum of last n nodes is : " << sum;
}

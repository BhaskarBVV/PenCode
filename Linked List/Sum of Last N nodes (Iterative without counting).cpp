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
int sumOfLastN_Nodes(ListNode *head, int n)
{
    int sum = 0;
    ListNode *temp = head, *temp2;
    while (n != 0)
    {
        temp = temp->next;
        n -= 1;
    }
    temp2 = head;
    while (temp != NULL)
    {
        temp2 = temp2->next;
        temp = temp->next;
    }
    while (temp2 != 0)
    {
        sum += temp2->val;
        temp2 = temp2->next;
    }
    return sum;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    int n;
    cout << "Enter the N-th node from end : ";
    cin >> n;
    cout << "The sum of last n nodes is : " << sumOfLastN_Nodes(head, n);
    //This is two pointer appraoch !!!
}

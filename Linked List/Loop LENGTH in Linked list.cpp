// 1->2->3->4->5->6->7->8
//       ^------LOOP----^
// Lenght = 6

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
void loop(ListNode *head, int pos)
{
    if (pos == 0)
        return;
    ListNode *tail = head, *loop_pos = head;
    while (tail->next != NULL)
        tail = tail->next;
    for (int i = 1; i < pos; i++)
        loop_pos = loop_pos->next;
    tail->next = loop_pos;
}
int Length_Of_Loop(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    // check if loop is present or not !
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    // return 0 if not present
    if (fast != slow)
        return 0;
    // else set one of the fast or slow to head, and do checking with other.
    fast = head;
    int cnt = 0;
    if (slow == head)
    {
        // This is the case when list is circular, i.e. loop from tail to head
        // Now move fast by 1 step until its next is equal to slow or move slow by 1 until its next is equal to fast.
        while (fast->next != slow)
        {
            cnt++;
            fast = fast->next;
        }
    }
    else
    {

        while (fast->next != slow->next)
        {
            // This loop brings slow and fast pointer to a position such that next of both will be pointing to the node from where loop starts.
            fast = fast->next;
            slow = slow->next;
        }
        // Bring both slow and fast to starting point of loop,
        fast = fast->next;
        slow = slow->next;
        // And move either slow or fast.
        // Here i've moved fast until its next is not equal to slow.
        while (fast->next != slow)
        {
            //line 93, 94.
            cnt++;
            fast = fast->next;
        }
    }
    return cnt + 1;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    int x;
    cout << "Enter the positon of creating loop (0 for no loop) : ";
    cin >> x;
    loop(head, x);
    cout << "\nThe length of loop is : " << Length_Of_Loop(head);
}

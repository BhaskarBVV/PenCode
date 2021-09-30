// Unlink the sublist from the rest of the list, reverse it and link it again.
  
// N = 10
// Linked List = 1->7->5->3->9->8->10->2->2->5->NULL
// m = 1, n = 8
// Output : 2 10 8 9 3 5 7 1 2 5 
// Explanation :
// The nodes from position 1 to 8 are reversed, resulting in 2 10 8 9 3 5 7 1 2 5.
  
  
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
ListNode *rev(ListNode *head, ListNode *end)
{
    ListNode *cur = head, *prev = NULL, *nxt = head;
    while (nxt != end)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
ListNode *reverseBetween(ListNode *head, int m, int n)
{
    ListNode *start_point = head, *pre_start_point = NULL;
    m -= 1;
    while (start_point && m)
    {
        m -= 1;
        pre_start_point = start_point;
        start_point = start_point->next;
    }
    ListNode *end_point = head, *post_end_point;
    while (end_point && n)
    {
        n -= 1;
        end_point = end_point->next;
        post_end_point = end_point;
    }
    ListNode *head_of_rev_list = rev(start_point, post_end_point);
    ListNode *lastNode_of_rev_list = head_of_rev_list;
    while (lastNode_of_rev_list->next != NULL)
    {
        lastNode_of_rev_list = lastNode_of_rev_list->next;
    }

    if (pre_start_point == NULL)
    {
        head = head_of_rev_list;
        lastNode_of_rev_list->next = post_end_point;
    }
    else
    {
        pre_start_point->next = head_of_rev_list;
        lastNode_of_rev_list->next = post_end_point;
    }
    return head;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "Original List : ";
    print(head);
    cout << endl;
    int a, b;
    cout << "Enter the ranges : ";
    cin >> a >> b;
    head = reverseBetween(head, a, b);
    cout << "\nThe list after reversing sublist : ";
    print(head);
}

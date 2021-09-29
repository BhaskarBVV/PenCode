// LinkList1 = 3->6->9->common
// LinkList2 = 10->common
// common = 15->30->NULL
// First intersection point: 15

//Bhaskar Varshney

#include <iostream>
#include <set>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
ListNode *BuildList()
{
    ListNode *head = NULL, *temp;
    int choice = 1;
    while (choice == 1)
    {
        ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
        cout << "Enter data : ";
        cin >> newnode->data;
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
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Count the length of both lists, 
// set the temp pointers of both lists, 
// x be the difference between the length of both lists, 
// Traverse the list with longer length by x units initially.
// Now enter both the lists in the loop until temp pointers of both have same address (i.e. they both point to same node, and is the first point of intersection).

int intersectPoint(ListNode *head1, ListNode *head2)
{
    ListNode *temp1 = head1, *temp2 = head2;
    int cnt1 = 0, cnt2 = 0, x;
    while (temp1 != 0)
    {
        cnt1++;
        temp1 = temp1->next;
    }
    while (temp2 != 0)
    {
        cnt2++;
        temp2 = temp2->next;
    }
    // cout<<cnt1<<" "<<cnt2<<endl;
    x = abs(cnt1 - cnt2);
    temp1 = head1, temp2 = head2;
    if (cnt1 > cnt2)
    {
        while (temp1 && x != 0)
        {
            temp1 = temp1->next;
            x--;
        }
    }
    else if (cnt2 > cnt1)
    {
        while (temp2 && x != 0)
        {
            temp2 = temp2->next;
            x--;
        }
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
            return temp1->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}
void combine(ListNode *head1, ListNode *head2, ListNode *chead)
{
    ListNode *t1 = head1, *t2 = head2;
    while (t1->next != NULL)
        t1 = t1->next;
    while (t2->next != NULL)
        t2 = t2->next;
    //merge common part to both lists.
    t1->next = chead;
    t2->next = chead;
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    cout << "Original List 1 : ";
    print(head);
    cout << "\nBuild list 2: \n";
    ListNode *head2 = BuildList();
    cout << "Original List 2 : ";
    print(head2);
    cout << "\nBuild intersection part : ";
    ListNode *chead = BuildList();
    cout << "Common part : ";
    print(chead);
    combine(head, head2, chead);
    cout << "\nThe first intersection point : " << intersectPoint(head, head2);
}

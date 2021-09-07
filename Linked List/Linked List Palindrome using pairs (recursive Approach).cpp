#include <iostream>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(nullptr) {}
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
ListNode *left = new ListNode(0);
pair<bool, ListNode *> is_Palindrome(ListNode *head, ListNode *left)
{
    if (head == NULL)
        return make_pair(true, left);//return {true and left Pointer value}. This left pointer value will be stored in result.second
    pair<bool, ListNode *> result = is_Palindrome(head->next, left);// Reached to end of list and same value of left pointer is transferred in each call until end.
    // When the end of list is achieved, the first condition returns {true and left pointer}into the result variable, 
    // Now for comparing extreme right head pointer will be used and for extreme left the result.second pointer will be used, instead of left pointer.
    // comparison will be as follows leftmost node(result.second) and rightmost node than second leftmost and second rightmost and so on.
    // cout << head->data << "A";
    // cout << left->data << endl;
    if (result.first == false)
    {
        //cout << "A";
        return make_pair(false, left);
    }
    else if (head->data != result.second->data)
    {
        //cout << "B";
        return make_pair(false, result.second);
    }
    else if (head->data == result.second->data)
    {
        //cout << "C";
        //if values of left(result.second) and right(head) nodes are same then move left pointer(result.second) ahead by one place and return that new position of left pointer in pair.
        return make_pair(true, result.second->next);
    }
    return make_pair(true, left);
}
int main()
{
    cout << "Build list : \n";
    ListNode *head = BuildList();
    ListNode *left = head;
    cout << "Is the list Palindrome : " << boolalpha << is_Palindrome(head, left).first;
}

//Bhaskar Varshney
#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
vector<ListNode *> find_mid(ListNode *head)
{
    if (head == NULL)
        return {NULL, NULL};
    else if (head->next == NULL)
        return {NULL, head};
    ListNode *temp, *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        temp = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    return {temp, slow};
}
TreeNode *sorted_List_To_BST(ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        TreeNode *root = new TreeNode(head->val);
        root->right = NULL;
        root->left = NULL;
        return root;
    }
    vector<ListNode *> v = find_mid(head);
    ListNode *middle = v[1];
    ListNode *prev_of_mid = v[0];
    prev_of_mid->next = NULL;
    TreeNode *root = new TreeNode(middle->val);
    root->left = sorted_List_To_BST(head);
    root->right = sorted_List_To_BST(middle->next);
    return root;
}
void List_Print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
void BST_preOrder_print(TreeNode *head)
{
    if (head == NULL)
        return;
    cout << head->val << " ";
    BST_preOrder_print(head->left);
    BST_preOrder_print(head->right);
}
int main()
{
    cout << "Build list : \n";
    ListNode *List_head = BuildList();
    cout << "The original list : ";
    List_Print(List_head);
    TreeNode *Treehead = sorted_List_To_BST(List_head);
    cout << "\nThe preOrder of formed tree is : ";
    BST_preOrder_print(Treehead);
}

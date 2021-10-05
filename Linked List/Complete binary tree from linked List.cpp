// The complete binary tree is represented as a linked list in a way where if root node is stored at position i, 
// its left, and right children are stored at position 2*i+1, 2*i+2 respectively.
// list-> 10 12 15 25 30 36
// complete Tree->          10
//                       /     \
//                     12       15
//                    /  \     /
//                  25    30  36

//Bhaskar Varshney
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
void InOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}
void convert(ListNode *head, TreeNode *&root)
{
    queue<TreeNode *> q;
    ListNode *list_temp = NULL;
    TreeNode *tree_temp = NULL;
    root = new TreeNode(head->val);
    list_temp = head->next;
    q.push(root);
    while (!q.empty())
    {
        tree_temp = q.front();
        q.pop();
        if (list_temp)
        {
            tree_temp->left = new TreeNode(list_temp->val);
            q.push(tree_temp->left);
            list_temp = list_temp->next;
        }
        if (list_temp)
        {
            tree_temp->right = new TreeNode(list_temp->val);
            q.push(tree_temp->right);
            list_temp = list_temp->next;
        }
    }
}
int main()
{
    TreeNode *root = NULL;
    ListNode *head = BuildList();
    convert(head, root);
    cout << "The inorder traversal of complete Binary tree is : ";
    InOrder(root);
}

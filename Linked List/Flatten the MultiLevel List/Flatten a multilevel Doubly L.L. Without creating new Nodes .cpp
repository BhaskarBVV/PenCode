// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
class Solution
{
public:
    Node *list_head = new Node();
    Node *temp;
    void dfs(Node *root)
    {
        if (root == NULL)
            return;
        while (root != NULL)
        {
            temp->next = root;
            root->prev = temp;
            temp = root; // or temp=temp->next;
			/*----------------------------------
			Before you go to the child nodes, you need to store the address of next Node of current Node.
			Becasue we are not creating the new nodes, but making changes only in provided nodes
			Hence, in order to add the child nodes to list we add them into the currentNode->next
			As a result the actual next Nodes of the current node are lost and the child nodes of current nodes are added*/
            Node *NextNode = root->next;
			//----------------------------------
            dfs(root->child);
            root->child = NULL;
			/*----------------------------------
			Now, move the root pointer ahead, but in root->next there are child nodes that are added by dfs
			Hence use the address of the next node that we previously stored in NextNode*/
            root = NextNode;
        }
    }
    Node *flatten(Node *head)
    {
        if(head==NULL)
            return head;
        list_head->val = -1;
        temp = list_head;
		//----------------------------------
        dfs(head);
		/*----------------------------------
		The head node with value (-1) should also be detached from newly formed flatten D.L.L.
		cannot return list_head->next;
		----------------------------------*/
        temp = list_head->next;
        temp->prev = NULL;
        list_head->next = NULL;
		//----------------------------------
        return temp;
    }
};

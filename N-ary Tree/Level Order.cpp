/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if(root==NULL)
            return {};
        vector<vector<int>> ans;
        vector<int> v;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        Node *temp;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                ans.push_back(v);
                v.clear();
                if (!q.empty())
                    q.push(NULL);
            }
            else
            {
                v.push_back(temp->val);
                for (auto it : temp->children)
                    q.push(it);
            }
        }
        return ans;
    }
};

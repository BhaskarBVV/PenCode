struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void getNode(Node *root, int target, Node *&tar)
{
    if (root == NULL)
        return;
    if (tar != NULL)
        return;
    if (root->data == target)
    {
        tar = root;
        return;
    }
    getNode(root->left, target, tar);
    if (tar != NULL)
        return;
    getNode(root->right, target, tar);
}



int minTime(Node *root, int target)
{
    if (root == NULL)
        return 0;
  
  
  //-----------------Assigning the parents of each root-------------------------STEP1
    map<Node *, Node *> mp;
    queue<Node *> q;
    Node *temp;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->left != NULL)
        {
            mp[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            mp[temp->right] = temp;
            q.push(temp->right);
        }
    }
  
  
  //-------------Find the Target Node* -------------------------------------------------------STEP2
    Node *tar = NULL;
    getNode(root, target, tar);
  
  
  //--------------Every node will spread find to left, right, and its parent (3directions)----------------------------------STEP3
  // Run for loop on all elements present in queue one time and count the burning of all these nodes as 1;
  //--------------To mark the visited array, let us use the set
    q.push(tar);
    set<Node *> s;
    s.insert(tar);
    int cnt = -1, size;
    while (!q.empty())
    {
        size = q.size();
        cnt++;
      // Process all the (n) nodes at same time and count them as 1 unit of time.
        for (int i = 0; i < size; i++)
        {
            temp = q.front();
            q.pop();
            if (temp->left && s.find(temp->left) == s.end())
            {
                s.insert(temp->left);
                q.push(temp->left);
            }
            if (temp->right && s.find(temp->right) == s.end())
            {
                s.insert(temp->right);
                q.push(temp->right);
            }
            if (mp.find(temp) != mp.end() && s.find(mp[temp]) == s.end())
            {
                s.insert(mp[temp]);
                q.push(mp[temp]);
            }
        }
    }
    return cnt;
}

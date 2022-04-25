struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

//lvl (level) is also needed as if we try to do with simple inorder treeHelper(root,idx,mp), than wrong storing will be done.
//             -2  -1 0  1 2 3   <<- these are the horizontal indexes.
// ex->               1
//                  /  \
//                 2    3
//               /  \
//              4    5 
//                    \
//                     6
//                      \
//                       7
//                        \
//                         8
  // Here we will be moving from 1->2->4->5->6, now 6 is at the idx=1 and idx is not curretly in map, as a result mp[1]=6, but instead mp[1] should be 3.
  // Hence, if there are multiple values at same idx then, the value at lower level will be stored.


void treeHelper(Node *root, int idx, int lvl, map<int, pair<int, int>> &mp)
{
    if (root == NULL)
        return;
    if (mp.find(idx) == mp.end())
        mp[idx] = {root->data, lvl};
    else
    {
        pair<int, int> temp = mp[idx];
        if (temp.second > lvl)
        {
            temp.first = root->data;
            temp.second = lvl;
        }
        mp[idx] = temp;
    }
    treeHelper(root->left, idx - 1, lvl + 1, mp);
    treeHelper(root->right, idx + 1, lvl + 1, mp);
}
vector<int> topView(Node *root)
{
    if (root == NULL)
        return {};
    // idx, <val, lvl>
    map<int, pair<int, int>> mp;
    treeHelper(root, 0, 0, mp);
    vector<int> ans;
    for (auto it : mp)
    {
        ans.push_back(it.second.first);
    }
    return ans;
}

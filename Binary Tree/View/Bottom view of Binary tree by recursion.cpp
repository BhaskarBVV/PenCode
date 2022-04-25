//explaination in top view by recursion.

class Solution {
  public:
    void treeHelper(Node *root, int idx, int lvl, map<int, pair<int, int>> &mp)
{
    if (root == NULL)
        return;
    if (mp.find(idx) == mp.end())
        mp[idx] = {root->data, lvl};
    else
    {
        pair<int, int> temp = mp[idx];
        if (temp.second <= lvl) 
        {
            temp.first = root->data;
            temp.second = lvl;
        }
        mp[idx] = temp;
    }
    treeHelper(root->left, idx - 1, lvl + 1, mp);
    treeHelper(root->right, idx + 1, lvl + 1, mp);
}
vector<int> bottomView(Node *root)
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
};

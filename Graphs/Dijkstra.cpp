class priorityQueue
{
public:
    vector<pair<int, int>> pq;
    priorityQueue()
    {
        pq.clear();
    }
    void add(pair<int, int> a)
    {
        pq.push_back(a);
        upHeapify(pq.size() - 1);
    }
    void swap(int i1, int i2)
    {
        pair<int, int> temp;
        temp = pq[i1];
        pq[i1] = pq[i2];
        pq[i2] = temp;
    }
    void upHeapify(int index)
    {
        if (index == 0)
            return;
 
        int parent = (index - 1) / 2;
        if (pq[index].second < pq[parent].second)
        {
            swap(index, parent);
            // cout << index << "," << parent << endl;
            upHeapify(parent);
        }
    }
    void remove()
    {
        if (pq.size() == 0)
            return;
        if (pq.size() == 1)
        {
            pq.clear();
            return;
        }
        swap(0, pq.size() - 1);
        pq.pop_back();
        downHeapify(0);
    }
    void downHeapify(int parent)
    {
        int minIdx = parent;
        int leftChild = 2 * parent + 1;
        int rightChild = 2 * parent + 2;
        if (leftChild < pq.size() && pq[leftChild].second < pq[minIdx].second)
            minIdx = leftChild;
        if (rightChild < pq.size() && pq[rightChild].second < pq[minIdx].second)
            minIdx = rightChild;
        if (minIdx != parent)
        {
            swap(parent, minIdx);
            downHeapify(minIdx);
        }
    }
    pair<int, int> peek()
    {
        return pq[0];
    }
    int size()
    {
        return pq.size();
    }
    bool empty()
    {
        if (pq.size() == 0)
            return true;
        return false;
    }
    // void print()
    // {
    //     for (auto it : pq)
    //         cout << it.first << " " << it.second << endl;
    // }
};
void dfs(vector<int> &ans, int i, vector<int> &parent, int &flag)
{
    // cout << i << endl;
    ans.push_back(i);
    if (i == 1)
        return;
    if (i == INT_MAX)
    {
        flag = 1;
        return;
    }
    dfs(ans, parent[i], parent, flag);
}
void solve()
{
    int n, m, a, b, wt;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    while (m--)
    {
        cin >> a >> b >> wt;
        adj[a - 1].pb({b - 1, wt});
        adj[b - 1].pb({a - 1, wt});
    }
    vector<ll> val(n, LONG_LONG_MAX);
    vector<int> parent(n + 1, INT_MAX);
    parent[0] = -1;
    val[0] = 0;
 
    priorityQueue pq;
    vector<bool> vis(n, false);
    // cout << "A" << endl;
    pq.add({0, 0});
    while (!pq.empty())
    {
        pair<int, int> temp = pq.peek();
        // cout << temp.first << " " << temp.second << endl;
        pq.remove();
        vis[temp.first] = true;
        // cout << u << endl;
        for (auto it : adj[temp.first])
        {
            if (vis[it.first] == false)
            {
                if (it.second + val[temp.first] < val[it.first])
                {
                    val[it.first] = val[temp.first] + it.second;
                    pq.add({it.first, val[it.first]});
                    parent[it.first + 1] = temp.first + 1;
                }
            }
        }
    }
    // cout << "B" << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Parent of " << i << ":" << parent[i] << "\n";
    // }
    vector<int> ans;
    int flag = 0;
    dfs(ans, n, parent, flag);
    reverse(ans.begin(), ans.end());
    if (*ans.begin() != 1 || flag == 1)
    {
        cout << -1;
        return;
    }
    for (auto it : ans)
        cout << it << " ";
}

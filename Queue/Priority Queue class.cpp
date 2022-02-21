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

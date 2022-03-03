#include <bits/stdc++.h>
using namespace std;
void makeSet(vector<int> &parent, vector<int> &rank)
{
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
// 1<-3<-5<-2
// find parent of 2
// parent[2]=findPar(parent[2]=5)
// parent[5]=findPar(parent[5]=3)
// parent[3]=findPar(parent[3]=1)
// parent[1]=findPar(parent[1]=1 hence return 1)
// parent[3]=1
// parent[5]=1
// parent[2]=1
int findPar(int node, vector<int> &parent)
{
    if (node == parent[node])
        return node;
    return parent[node] = findPar(parent[node], parent);
}
void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    // for the two nodes of same rank, you can make any one as parent and increase it rank
    // else make the node with higher rank as parent but here do not change the ranks.
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] == rank[v])
    {
        // making u as parent of v and increase the rank of u;
        parent[v] = u;
        rank[u] += 1;
    }
    else if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
}
int main()
{
    int n, u, v;
    cin >> n;
    vector<int> parent(n), rank(n);
    while (n--)
    {
        cin >> u >> v;
        Union(u, v, parent, rank);
    }
    if (findPar(2, parent) != findPar(3, parent))
        cout << "Diff Parent";
    else
        cout << "same Parernt";
}

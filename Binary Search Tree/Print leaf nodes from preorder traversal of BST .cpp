//Bhaskar Varshney

// simialr for postorder...

// In preOrder of BST, The first value is root node and rest are child nodes, the values samller than first value will come in left subtree and 
// values greater than first will come in right subtree.
// PREORDER--structure-->>>>  <root> <smaller values(left Subtree)> <Right subtree(greater values)> 

#include <iostream>
#include <queue>
using namespace std;
void leafNodes(vector<int> a, int s, int e, vector<int> &v)
{
    if (s > e)
        return;
    int root = a[s];
    if (s == e)
    {
        v.push_back(root);
        return;
    }
    int i;
    for (i = s + 1; i <= e; i++)
        if (a[i] > root)
            break;
    leafNodes(a, s + 1, i - 1, v);
    leafNodes(a, i, e, v);
}
int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "Enter the preOrder traversal of BST : ";
    vector<int> a(n);
    for (auto &it : a)
        cin >> it;
    vector<int> v;
    leafNodes(a, 0, n - 1, v);
    cout << "The leaf nodes will be ";
    for (auto it : v)
        cout << it << " ";
}

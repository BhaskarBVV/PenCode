// N = 7
// arr[] = {7 6 5 4 3 2 1}
// childs at 2i+1, 2i+2.
// Output:
// 7
// 5 6
// 1 2 3 4
// Explanation: The formed Binary Tree is:
//              7
//           /      \
//         6         5
//       /  \      /   \
//      4    3    2     1

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> binTreeSortedLevels(int a[], int n)
{
    vector<int> v;
    vector<vector<int>> v2;
    queue<int> q;
    int x;
    q.push(0);
    q.push(-1);
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        if (x != -1)
        {
            v.push_back(a[x]);
            if (2 * x + 1 < n)
                q.push(2 * x + 1);
            if (2 * x + 2 < n)
                q.push(2 * x + 2);
        }
        else
        {
            sort(v.begin(), v.end());
            v2.push_back(v);
            v.clear();
            if (!q.empty())
            {
                q.push(-1);
            }
        }
    }
    return v2;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    cout << "Enter the array : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> v = binTreeSortedLevels(a, n);
    cout << "\nThe Sorted level order traversal : \n";
    for (auto it : v)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
}

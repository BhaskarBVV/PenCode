#include <bits/stdc++.h>
using namespace std;
vector<int> findUnion(int a1[], int a2[], int n, int m)
{
    vector<int> v;
    int i = 0, j = 0, x = INT_MIN;
    while (i < n && j < m) // Merging until one of them gets over.
    {
        cout << a1[i] << " " << a2[j] << endl;
        if (a1[i] == a2[j] && a1[i] != x)
        {
            x = a1[i];
            v.push_back(a1[i]);
            i++;
            j++;
        }
        else if (a1[i] == a2[j] && a1[i] == x)
        {
            i++;
            j++;
        }
        else if (a1[i] < a2[j] && a1[i] != x)
        {
            x = a1[i];
            v.push_back(a1[i]);
            i++;
        }
        else if (a1[i] < a2[j] && a1[i] == x)
        {
            i++;
        }
        else if (a1[i] > a2[j] && a2[j] != x)
        {
            x = a2[j];
            v.push_back(a2[j]);
            j++;
        }
        else if (a1[i] > a2[j] && a2[j] == x)
            j++;
    }
    // now merging leftover arrays
    while (i < n)
    {
        if (a1[i] != x)
        {
            x = a1[i];
            v.push_back(a1[i]);
            i++;
        }
        else
            i++;
    }
    while (j < m)
    {
        if (a2[j] != x)
        {
            x = a2[j];
            v.push_back(a2[j]);
            j++;
        }
        else
            j++;
    }
    return v;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector<int> v = findUnion(a, b, n, m);
    for (auto it : v)
        cout << it << " ";
}

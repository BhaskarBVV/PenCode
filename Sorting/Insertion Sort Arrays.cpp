#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, value;
    cout << "Enter the size of array : ";
    cin >> n;
    int a[n];
    cout << "\nEnter the array : ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 1; i < n; i++)
    {
        value = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > value)
        {
            a[j + 1] = a[j];
            j--;
        }
        j += 1;
        a[j] = value;
    }
    cout << "\nThe Sorted array will be : \n";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}

#include <iostream>
using namespace std;
int main()
{
    int n, mn, j, i;
    cout << "Enter the size of array : ";
    cin >> n;
    int a[n];
    cout << "Enter the array : \n";
    for (i = 0; i < n; i++)
        cin >> a[i];
    //sorting
    for (i = 0; i < n - 1; i++)
    {
        mn = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[mn])
            {
                mn = j;
            }
        }
        if (mn != i)
            swap(a[i], a[mn]);
    }
    cout << "\nThe array after sorting will be : ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}

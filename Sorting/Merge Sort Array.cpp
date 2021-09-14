#include <iostream>
using namespace std;
void merge(int a[], int s, int mid, int e)
{
    int i = s, j = mid + 1, k = 0, tot = e - s + 1;
    int temp[tot];
    while (i <= mid && j <= e)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= e)
    {
        temp[k++] = a[j++];
    }
    k = 0;
    for (int i = s; i <= e; i++)
        a[i] = temp[k++];
}
void merge_sort(int a[], int s, int e)
{
    if (s >= e)
        return; // array have one or zero elements !!
    int mid = (s + e) / 2;
    merge_sort(a, s, mid);
    merge_sort(a, mid + 1, e);
    merge(a, s, mid, e);
}
int main()
{
    cout << "Enter the size of array : ";
    int n;
    cin >> n;
    int a[n];
    cout << "Enter the array : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(a, 0, n);
    cout << "The array after sorting : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

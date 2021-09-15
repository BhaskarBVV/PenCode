#include <iostream>
using namespace std;
int merge(int a[], int s, int mid, int e)
{
    int i = s, j = mid + 1, k = 0, tot = e - s + 1;
    int temp[tot];
    int cnt = 0;
    while (i <= mid && j <= e)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            cnt += (mid - i + 1);
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
    return cnt;
}
int merge_sort(int a[], int s, int e)
{
    if (s >= e)
        return 0; // array have one or zero elements !!
    int mid = (s + e) / 2;
    int x = merge_sort(a, s, mid);
    int y = merge_sort(a, mid + 1, e);
    int z = merge(a, s, mid, e);
    return x + y + z;
}
int main()
{
    cout << "Enter the size of array : ";
    int n, cnt = 0;
    cin >> n;
    int a[n];
    cout << "Enter the array : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cnt = merge_sort(a, 0, n);
    cout << "The array after sorting : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "The total number of inversions are: " << cnt;
}

#include <iostream>
using namespace std;
bool Binary_search(int a[], int k, int s, int e)
{
    if (s > e)
        return false;
    int mid = s + (e - s) / 2;
    if (a[mid] == k)
        return true;
    if (a[mid] < k)
        return Binary_search(a, k, mid + 1, e);
    if (a[mid] > k)
        return Binary_search(a, k, s, mid - 1);
    return false;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 100};
    int key;
    cout << "Enter the value to be searched : ";
    cin >> key;
    int start = 0, end = sizeof(a) / sizeof(int) - 1;
    cout << "\nIs key present : " << boolalpha << Binary_search(a, key, start, end);
}

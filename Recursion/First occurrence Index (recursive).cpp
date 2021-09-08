#include <iostream>
using namespace std;
int first(int a[], int s, int n, int k)
{
    //METHOD 1
    if (s > n)
        return -1;
    if (a[s] == k)
        return s;
    return first(a, s + 1, n, k);
}
int firstOcc(int a[], int n, int k)
{
    //METHOD 2
    if (n == 0)
        return -1;
    if (a[0] == k)
        return 0;
    int i = firstOcc(a + 1, n - 1, k);
    if (i == -1)
        return -1;

    return i + 1;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 100};
    int size = sizeof(a) / sizeof(int);
    cout << "Enter the Key whose first occurence index is to be founded: ";
    int key;
    cin >> key;
    int start = 0;
    cout << firstOcc(a, size, key);
    // cout << first(a, start, size, key);
}

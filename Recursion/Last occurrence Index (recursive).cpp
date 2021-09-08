#include <iostream>
using namespace std;
int Last(int a[], int e, int n, int k)
{
    //METHOD 1
    if (e < 0)
        return -1;
    if (a[e] == k)
        return e;
    return Last(a, e - 1, n, k);
}
int LastOcc(int a[], int n, int k)
{
    //METHOD 2
    if (n == 0)
        return -1;
    int i = LastOcc(a + 1, n - 1, k);
    if (a[0] == k && i == -1)
        return 0;
    if (i != -1)
        return i + 1;
    return -1;
}
int main()
{
    int a[] = {1, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1};
    int size = sizeof(a) / sizeof(int);
    cout << "Enter the Key whose Last occurence index is to be founded: ";
    int key;
    cin >> key;
    int start = 0;
    cout << LastOcc(a, size, key) << endl;
    cout << Last(a, size - 1, size, key);
}

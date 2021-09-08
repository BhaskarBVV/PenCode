#include <iostream>
using namespace std;
bool chk(int a[], int s, int e)
{
    if (s == e || s + 1 == e)
        return true;
    bool x = chk(a, s + 1, e);
    if (a[s] <= a[e] && x == true)
        return true;
    return false;
}
int main()
{
    int a[] = {9, 97, 902, 1002, 2000, 2002, -1};
    int size = sizeof(a) / sizeof(int);
    cout << "Is array sorted : " << boolalpha << chk(a, 0, size - 1);
}

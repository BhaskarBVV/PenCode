//Bhaskar Varshney
#include <iostream>
using namespace std;
int majorityElement(int a[], int size)
{
    int ele = a[0], count = 1;
    for (int i = 1; i < size; i++)
    {
        if (ele == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            ele = a[i];
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < size; i++)
        if (a[i] == ele)
            count++;

    if (count > size / 2)
        return ele;
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x = majorityElement(a, n);
    if (x != -1)
        cout << "The majority element is : " << x;
    else
        cout << "Not Present ";
}

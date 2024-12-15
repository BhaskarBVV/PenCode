#include <bits/stdc++.h>
using namespace std;
#define max 10000
int main()
{
    int n, c, j, k, x, i;
    int a[max];
    cout << "Enter the number: ";
    cin >> n;
    j = 0; // j will be pointing to new index created to stored carry
    a[0] = 1;
    for (i = 2; i <= n; i++)
    {
        c = 0; //carry when each number of array is multiplied by i
        //(i is a part of numbers that come in factorial)
        //every number will be multiplied to array from starting index.
        for (k = 0; k <= j; k++)
        {
            x = (a[k] * i) + c;
            a[k] = x % 10;
            c = x / 10;
        }
        //In case end carry is of more than one digit...
        //digits are stored in reverse order..
        while (c != 0)
        {
            a[++j] = c % 10;
            c /= 10;
        }
    }
    //print array in reverse order..
    for (i = j; i >= 0; i--)
        cout << a[i];
}

#include <iostream>
using namespace std;
long long int power(int x, int n)
{
    if (n == 0)
        return 1;
    // long long int x_power_nb2 = power(x, n / 2);
    // long long int x_power_n = (x_power_nb2) * (x_power_nb2);
    // if (n % 2 == 1)
    //     x_power_n *= x;
    // return x_power_n;
    // OR

    long long int pxnb2 = power(x, n / 2);
    if (n % 2 == 0)
        return pxnb2 * pxnb2;
    else
        return x * pxnb2 * pxnb2;

    // (2,16)=(2,8)*(2,8); n is even
    // (2,15)=(2,7)*(2,7)*2; n is odd
}
int main()
{
    int n, x;
    cin >> n >> x;
    cout << power(n, x);
}

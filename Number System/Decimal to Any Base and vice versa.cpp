#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int getDigitFrequency(int n, int d)
{
    int occu = 0;
    while (n != 0)
    {
        int ld = n % 10;
        n /= 10;
        if (ld == d)
            occu++;
    }

    return occu;
}
int decimalToBinary(int n)
{
    int ans = 0, pow = 1;
    while (n != 0)
    {
        int rem = n % 2;
        n /= 2;

        ans += rem * pow;
        pow = pow * 10;
    }

    return ans;
}
int binaryToDecimal(int n)
{
    int ans = 0, pow = 1;
    while (n != 0)
    {
        int rem = n % 10;
        n /= 10;

        ans += rem * pow;
        pow = pow * 2;
    }

    return ans;
}
int decimalToanyBase(int n, int b)
{
    int pow = 1, ans = 0;
    while (n != 0)
    {
        int rem = n % b;
        n /= b;

        ans += rem * pow;
        pow *= 10;
    }

    return ans;
}
int anyBaseToDecimal(int n, int b)
{
    int pow = 1, ans = 0;
    while (n != 0)
    {
        int rem = n % 10;
        n /= 10;

        ans += rem * pow;
        pow *= b;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    int binary = decimalToBinary(n);
    cout << binary;

    int decimal = binaryToDecimal(binary);
    cout << decimal;
}

//Bhaskar Varshney
#include <iostream>
#include <vector>
using namespace std;
long long int fib(int n)
{
    int dp[1000]{0};
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    cout << "The nth fib term will be : " << fib(n);
}


// In order to reduce space complexity use 3 variables a,b,c
// c=a+b;
// a=b;
// b=c;
// Time comp O(N)
// space comp O(1)

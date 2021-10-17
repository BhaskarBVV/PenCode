//Bhaskar Varshney
#include <iostream>
#include <vector>
using namespace std;
long long int fib(int n, int dp[])
{
    if (n == 0 || n == 1)
        return n;
    else if (dp[n] != 0)
        return dp[n];
    int ans;
    ans = (fib(n - 1, dp) % 1000000007 + fib(n - 2, dp) % 1000000007) % 1000000007;
    // The ans will be long, so modulo by 10e9+7;
    return dp[n] = ans;
}
int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int dp[1003]{0};
    cout << "The nth fib term will be : " << fib(n, dp);
}

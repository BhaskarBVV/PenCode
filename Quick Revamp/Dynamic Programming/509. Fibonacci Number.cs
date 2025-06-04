// https://leetcode.com/problems/fibonacci-number/description/

public class Solution {
    private static Dictionary<int,int>dp;
    public Solution()
    {
        dp = new Dictionary<int,int>();
    }
    public int Fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        else if(dp.ContainsKey(n)){
            return dp[n];
        }
        int fib_n = Fib(n-1)+Fib(n-2);
        dp[n] = fib_n;
        return dp[n];
    }
}

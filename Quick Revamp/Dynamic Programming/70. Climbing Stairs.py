# https://leetcode.com/problems/climbing-stairs/

# using tabulation
class Solution:
    def climbStairs(self, n: int) -> int:
        if n==1:
            return 1
        if n==2:
            return 2
        dp = [0]*(n+1)
        dp[1] = 1
        dp[2] = 2
        for stair_number in range(3, n+1):
            dp[stair_number] = dp[stair_number-1] + dp[stair_number-2]        
        return dp[n]
    


# using memorization
class Solution:
    def __init__(self):
        self.dp = {}

    def climbStairs(self, n: int) -> int:        
        if n == 1:
            return 1
        if n == 2:
            return 2
        if self.dp.get(n):
            return self.dp[n]
        self.dp[n]= self.climbStairs(n-1) + self.climbStairs(n-2)
        return self.dp[n]
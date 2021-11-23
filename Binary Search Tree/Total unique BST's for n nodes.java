class Solution {
    public int numTrees(int n) {
        int [] dp= new int[n+1];
        dp[0]=1;
        dp[1]=1;
        
        int i,l,r;
        for(i=2;i<=n;i++)
        {
            l=0;
            r=i-1;
            while(l<=i-1)
            {
                dp[i]+=dp[l]*dp[r];
                l++;
                r--;
            }
        }
        
        return dp[n];
    }
}

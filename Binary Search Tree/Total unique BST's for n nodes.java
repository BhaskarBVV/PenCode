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


// Nodes-----------------BST's
// ->  0      -----       1
// ->  1      -----       1
    
// ->  2      -----    f(0)*f(1)+f(1)*f(0)
//  ex-10,20
//     10               20
//    /  \            /   \
//   x    20         10    x
// f(0) * f(1)  +  f(1) * f(0)
    
// ->  3      -----    f(0)*f(2) + f(1)*f(1) + f(2)*f(0)
// ex-10,20,30
//     10                20                30      
//    /  \              /  \             /   \
//   x  20,30          10  30         10,20   x
//     we know                       we know 
//     the number                   the number
//     of BST for                   of BST for 
//     2 BST's                        2 BST's
//  f(0)*f(2)  +    f(1) * f(1)   +   f(2) * f(0)
        
// -> 4     ------     f(0)*f(3) + f(1)*f(2) + f(2)*f(1) + f(3)*f(0)
//                     left value increases and right value decreases.
//                     left = 0 -> n-1 and right = n-1 -> 0.


// similar to catalan numbers...

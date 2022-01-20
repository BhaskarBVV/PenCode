class Solution {
  public:
    int makeProductOne(int a[], int N) {
        int cnt=0,n=0,z=0;
        for(int i=0;i<N;i++)
        {
            if(a[i]==0)
            z++;
            else if(a[i]>0)
            {
                cnt+=(a[i]-1);
            }
            else
            {
                cnt+=(-1-a[i]);
                n+=1;
            }
        }
        if(n%2!=0)
            {
                if(z==0)
                cnt+=2;
                else
                {
                    cnt+=1;
                    z-=1;
                }
            }
        cnt+=z;
        return cnt;
    }
};

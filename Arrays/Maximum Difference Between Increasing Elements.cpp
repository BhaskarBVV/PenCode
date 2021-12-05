class Solution {
public:
    int maximumDifference(vector<int>& a)
    {
        int n=a.size();
        int mx=a[n-1],dif=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]<mx)
            {
                dif=max(dif,mx-a[i]);
            }
            else if(a[i]>mx)
                mx=a[i];
        }
        return dif;
    }
};

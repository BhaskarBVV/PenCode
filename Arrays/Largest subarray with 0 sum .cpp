int maxLen(vector<int>&a, int n)
    {   
        int i, mx_len=0;
        for(i=1;i<n;i++)
            a[i]=a[i]+a[i-1];
        unordered_map<int,int>mp;
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
            mx_len=max(mx_len,i+1);
            if(mp.find(a[i])!=mp.end())
            {
                mx_len=max(mx_len,i-mp[a[i]]);
            }
            else
            {
                mp[a[i]]=i;
            }
        }
        return mx_len;
    }

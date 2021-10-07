bool subArrayExists(int a[], int n)
    {
        int i;
        for(i=1;i<n;i++)
        a[i]=a[i]+a[i-1];
        set<int>s;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            return true;
            else if(s.find(a[i])!=s.end())
            return true;
            else
            s.insert(a[i]);
        }
        return false;
    }

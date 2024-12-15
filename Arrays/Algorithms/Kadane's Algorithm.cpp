long long maxSubarraySum(int a[], int n)
    {
        long long int sum=0, mx_sum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            mx_sum=max(mx_sum,sum);
            if(sum<0)
            sum=0;
        }
        return mx_sum;
    }

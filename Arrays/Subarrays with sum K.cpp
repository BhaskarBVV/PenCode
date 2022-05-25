//Bhaskar Varshney
int findSubArraySum(int a[], int n, int k)
    {
        map<int,int>mp;
        mp[0]++;
        // there might be sub array with sum=k hence no need to find sum-k in map to increase the count
  //ex-> array: 1 2 4 6, k=7, hence at index i=2 sum will be 7 and if we subtract sum-k(7-7=0) 0 will not be in map, hence we've added (0,0) in map.
        int cnt=0,sum=0;
        for(int i=0;i<n;i++)
        {
          // In this we are increasing sum at every step and storing it in map and checking if sum-k exists in array
          // if it exsits than it means that there is subarray with sum=sum-k and sum of current subarray is sum hence there will be an araay with sum=k
          //(current subarray with sum=sum and previous subarray with sum =sum-k hence, sum-(sum-k)=k is the resulting subarray)
          // There can be multiple previous subarrays with sum=sum-k, hence cnt+=the freuency of sum-k;
            sum+=a[i];
            if(mp.find(sum)==mp.end())
            mp[sum]++;
            else
            mp[sum]++;
            if(mp.find(sum-k)!=mp.end())
            {
                cnt+=mp[sum-k];
            }
        }
        return cnt;
    }




// OR

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        map<int,int>mp;
        int ans=0,sum=0;

        mp[0]=1;
        
        for(int i=0;i<N;i++)
        {
            sum+=Arr[i];

            if(mp.find(sum-k)!=mp.end())
            ans+=mp[sum-k];

            mp[sum]++;
        }
        return ans;
    }
};



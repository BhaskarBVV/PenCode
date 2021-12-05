// Input: nums = [7,1,5,4]
// Output: 4
// Explanation:
// The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
// Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.

// Input: nums = [9,4,3,2]
// Output: -1
// Explanation:
// There is no i and j such that i < j and nums[i] < nums[j].

// Input: nums = [1,5,2,10]
// Output: 9
// Explanation:
// The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.

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

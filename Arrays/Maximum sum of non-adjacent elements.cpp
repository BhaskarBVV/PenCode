// Input: nums = [1,2,3,1]
// Output: 4

// Input: nums = [2,7,9,3,1]
// Output: 12

// Input: nums = [5,10,10,100,5,6]
// Output: 116

class Solution {
public:
    int MaxSum(vector<int>& nums) 
    {
        int n=nums.size(), mx=0;
        int include[n], exclude[n];
        include[0]=nums[0], exclude[0]=0;
        mx=max(include[0],exclude[0]);
        for(int i=1;i<n;i++)
        {
            include[i]=exclude[i-1]+nums[i];
            exclude[i]=max(include[i-1], exclude[i-1]);
            mx=max(include[i],exclude[i]);
        }
        return mx;
    }
};

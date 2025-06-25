// https://leetcode.com/problems/contiguous-array/
// Similar to the question of count number of sub-arrays, where we were keeping the count of sum, 
// here we will keep the first location where the sum k was found... in order to find the longest sub-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int current_sum = 0, ans = 0;
        map<int,int>first_occurence_of_sum;
        first_occurence_of_sum[0]=-1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
                current_sum+=1;
            else
                current_sum-=1;

            if(first_occurence_of_sum.find(current_sum)!=first_occurence_of_sum.end())
                ans = max(ans, i-first_occurence_of_sum[current_sum]);
            else
                first_occurence_of_sum[current_sum]=i;
        }
        return ans;
    }
};

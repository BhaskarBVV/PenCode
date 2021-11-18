class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int>v;
        vector<vector<int>>res;
        int tot=pow(2,nums.size());
        for(int i=0;i<tot;i++)
        {
            int temp=i,r;
            v.clear();
            for(int j=nums.size()-1;j>=0;j--)
            {
                r=temp%2;
                temp=temp/2;
                if(r==1)
                    v.push_back(nums[j]);
            }
            reverse(v.begin(),v.end());
            res.push_back(v);
        }
        return res;
    }
};

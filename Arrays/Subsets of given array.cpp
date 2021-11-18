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

// a={1,2,3}
// Total subsets = 2^n;
//                                                           Subset
//    Num    Binary   ->                                     {123}
//     0      000     ->                                      ---
//     1      001     ->                                      --3
//     2      010     ->    Place number in place of 1        -2-
//     3      011     ->      in binary notation.             -23
//     4      100     ->                                      1--
//     5      101     ->                                      1-3
//     6      110     ->                                      12-
//     7      111     ->                                      123

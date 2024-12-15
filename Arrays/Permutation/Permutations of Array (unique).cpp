class Solution {
public:
    void backtrack(set<vector<int>>&s, vector<int>nums, vector<int>cur, bool visited[])
    {
        if(cur.size()==nums.size())
        {  
            s.insert(cur);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==false)
            {
                cur.push_back(nums[i]);
                visited[i]=true;
                backtrack(s,nums,cur,visited);
                cur.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        set<vector<int>>s;
        vector<vector<int>>res;
        vector<int>cur;
        bool visited[nums.size()];
        
        for(int i=0;i<nums.size();i++)
            visited[i]=false;
        backtrack(s, nums, cur, visited);
        for(auto it: s)
            res.push_back(it);
        return res;
    }
};

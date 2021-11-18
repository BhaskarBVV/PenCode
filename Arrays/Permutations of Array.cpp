class Solution 
{  
  // used bactracking 
  // inserted one by one all the elements in current vector (storing single permutation) and pushed that current vector in my result vector when all the elements are in current vector.
  // while coming back removed all the popped elements one by one and turned their visited to false;
  // Its similar to formation on binary tree, i.e, constructed left->left->left->left->.....then came back all way to root.
public:
    void backtrack(vector<vector<int>>&res, vector<int>nums,vector<int>cur, bool visited[])
    {
        if(cur.size()==nums.size())
        {
            res.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==true)  
                continue;
            cur.push_back(nums[i]);
            visited[i]=true;
            backtrack(res, nums, cur, visited);
            cur.pop_back();
            visited[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>res;
        vector<int>v;
        bool visited[nums.size()];
        
        for(int i=0;i<nums.size();i++)
            visited[i]=false;
        backtrack(res, nums, v, visited);
        return res;
    }
};

// Input: nums = ["01","10"]
// Output: "11"
// Explanation: "11" does not appear in nums. "00" would also be correct.
  
// Input: nums = ["00","01"]
// Output: "11"
// Explanation: "11" does not appear in nums. "10" would also be correct.
  
// Input: nums = ["111","011","001"]
// Output: "101"
// Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.


class Solution {
public:
    void backtrack(map<string,int>&mp, string temp, int st, int n, int &flag, string & res)
    {
        if(flag==1)// if string is found, no need to backtack
            return;
        if(temp.size()==n)
        {
            if(mp.find(temp)==mp.end() && flag==0)
            {
                res=temp;
                flag=1;
            }
            return;
        }
        for(int i=st;i<n;i++) // append 0 and 1 until size of string
        {
            if(flag==1)
            return;
            
            temp+='1';
            backtrack(mp,temp,st+1,n,flag,res);
            if(flag==1) // if string is found, no need to backtack
            return;
            
            temp.pop_back();
            
            temp+='0';
            backtrack(mp,temp,st+1,n,flag,res);
            if(flag==1)// if string is found, no need to backtack
            return;
            temp.pop_back();
        }
        
    }
    string findDifferentBinaryString(vector<string>& nums) 
    {
        map<string,int>mp;
        for(auto it: nums)
            mp[it]=1;
        int n=nums[0].size(),start=0,flag=0;
        string temp="",res="";
        backtrack(mp,temp,start,n,flag,res);
        return res;
    }
};

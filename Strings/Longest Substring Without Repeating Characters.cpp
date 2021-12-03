class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        map<char,int>mp;
        int i=0,j=0,cnt=0,mx=0;
        while(j<s.size())
        {
            if(mp[s[j]]==0)
            {
                cnt=j-i+1;
                mp[s[j]]++;
                j++;
            }
            else
            {
                mx=max(mx,cnt);
                while(mp[s[j]]!=0)
                {
                    mp[s[i]]-=1;
                    i++;
                }
            }
        }
        mx=max(cnt,mx);
        return mx;
    }
};

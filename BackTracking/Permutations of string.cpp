class Solution
{
	public:
	void backtrack(vector<string>&res, string s , string cur, bool visited[])
    {
        if(cur.size()==s.size())
        {
            res.push_back(cur);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            if(visited[i]==true)  
                continue;
            cur+=s[i];
            visited[i]=true;
            backtrack(res,s,cur,visited);
            cur.pop_back();
            visited[i]=false;
        }
    }
		vector<string>find_permutation(string s)
		{
		    vector<string>res;
            string cur="";
            bool visited[s.size()];
            for(int i=0;i<s.size();i++)
                visited[i]=false;
            backtrack(res, s, cur, visited);
            sort(res.begin(),res.end());
            return res;
		}
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>&v) 
    {
        sort(v.begin(),v.end());
        vector<vector<int>>v1;
        v1.push_back(v[0]);
        int pos=0;
        for(int i=1;i<v.size();i++)
        {
            int x=v[i][0];
            int y=v[i][1];
            int a=v1[pos][0];
            int b=v1[pos][1];
            if(x>=a && x<=b)
            {
                v1.pop_back();
                v1.push_back({a,max(y,b)});
            }
            else
            {
                v1.push_back({x,y});
                pos+=1;
            }
        }
        return v1;
    }
};

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Input: digits = ""
// Output: []

// Input: digits = "2"
// Output: ["a","b","c"]

class Solution {
public:
    void solve(string digits, int d, string res, vector<string>&v, map<int,vector<char>>&mp)
    {
        if(res.size()==digits.size())
        {
            v.push_back(res);
            return;
        }
        int x=digits[d]-'0';
      // pehle x ke associated saare characters append honge ek ke baad ek, saath hi ek char append hote hi input string ke next digits se associated char append honge,
      // fir aur next digit se associated characters, and so on. last digit par pahunchne ke baad pop honge peeche aate hue.
        for(auto it : mp[x])
        {
            res+=it;
            solve(digits,d+1,res,v,mp);
            res.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.size()==0)
            return {};
        map<int,vector<char>> m=
        {
        {2,{'a','b','c'}},
        {3,{'d','e','f'}},
        {4,{'g','h','i'}},
        {5,{'j','k','l'}},
        {6,{'m','n','o'}},
        {7,{'p','q','r','s'}},
        {8,{'t','u','v'}},
        {9,{'w','x','y','z'}}
        };
        string res="";
        vector<string>v;
        solve(digits,0,res,v,m);
        return v;
    }
};

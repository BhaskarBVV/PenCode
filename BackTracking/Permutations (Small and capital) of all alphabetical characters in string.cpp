// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]

// Input: s = "0"
// Output: ["0"]

// Input: s = "12345"
// Output: ["12345"]

// Input: s = "3z4"
// Output: ["3z4","3Z4"]

class Solution {
public:
    void backtrack(string s, string str, int st, vector<string>&v)
    {
        if(str.size()==s.size())
        {
            v.push_back(str);
            return;
        }
        for(int i=st;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
              // Numbers will have no permutations over sizes.
                str+=s[i];
                backtrack(s,str,i+1,v);
                str.pop_back();
            }
            else
            {
                str+=s[i];
                backtrack(s,str,i+1,v);
                str.pop_back();
              
              // The above three lines will bw used to generate the permutations with given character
              // and below code will be used to generate permutataions with opp. size as that of given character.
              // ex->s[i]='p'
              // then above 3 lines will generate permutations with 'p' and below code will generate permutations with 'P'
                
                if(s[i]>='a' && s[i]<='z')
                {
                    str+=s[i]-32;
                    backtrack(s,str,i+1,v);
                    str.pop_back();
                }
                else if(s[i]>='A' && s[i]<='Z')
                {
                    str+=s[i]+32;
                    backtrack(s,str,i+1,v);
                    str.pop_back();
                }
            }
        }
    }
    vector<string> letterCasePermutation(string s)
    {
        vector<string>v;
        string str="";
        int start=0;
        backtrack(s,str,start,v);
        return v;
    }
};

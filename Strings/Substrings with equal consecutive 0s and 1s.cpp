// Input: s = "00110011"
// Output: 6
// Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

// count the characters of same type and push their count in vector.
// Now for every two consecutive counts, the subtring formed by 0's and 1's will have minimum number of count of zero and ones

// str ->> 000111001101
//         000 111 00 11 0 1
// vect->> 3 3 2 2 1 1
// ex->total substrings with equal 0 and 1 formed from 000111 = min(3,3)=3 [000111, 0011, 01]
  
class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        vector<int>v;
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            if(temp=="")
                temp+=s[i];
            else if(*temp.rbegin()!=s[i])
            {
                v.push_back(temp.size());
                temp=s[i];
            }
            else 
                temp+=s[i];
        }
        if(temp!="")
            v.push_back(temp.size());
        int cnt=0;
        // for(auto it: v)
        //     cout<<it<<endl;
        for(int i=0;i<v.size()-1;i++)
            cnt+=min(v[i],v[i+1]);
        return cnt;
    }
};

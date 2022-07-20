class Solution
{
public:
  
  
  
  
  
    pair<char, char> find_mis_match(string a, string b)
    {
        for (int i = 0; i < a.size() && i < b.size(); i++)
        {
            if (a[i] != b[i])
            {
                return {a[i], b[i]};
            }
        }
        return {};
    }
  
//   ex: abc, acb   --->>> then index 2 is not same, hence connect b-->>c,
  
  
  
  
    void dfs(char ch, map<char, vector<char>> &mp, set<char> &st, stack<char> &s)
    {
        st.insert(ch);
        for (auto it : mp[ch])
        {
            if (st.find(it) == st.end())
            {
                dfs(it, mp, st, s);
                s.push(it);
            }
        }
    }
  
  
  
  
  
  
    string findOrder(string dict[], int N, int K)
    {
        map<char, vector<char>> mp;
//      For every two adjacent characters find their mismatch, and map them into the adjacency list.
        for (int i = 0; i < N - 1; i++)
        {
            pair<char, char> order = find_mis_match(dict[i], dict[i + 1]);
            mp[order.first].push_back(order.second);
        }

      
      
//      Now do simple Toplogical sorting on the adj list.
        stack<char> s;
        set<char> st;
        for (auto it : mp)
        {
            if (st.find(it.first) == st.end())
            {
                dfs(it.first, mp, st, s);
                s.push(it.first);
            }
        }
        string ans = "";
        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};

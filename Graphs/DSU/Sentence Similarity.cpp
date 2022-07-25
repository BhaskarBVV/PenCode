// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/graphs/sentence_similarity_official/ojquestion#!

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  
  
  
    string find_par(string s, map<string, string> &parent)
    {
        if (parent[s] == s)
            return s;
        return parent[s] = find_par(parent[s], parent);
    }
  
  
  
  
  
    void Union(string a, string b, map<string, int> &rank, map<string, string> &parent)
    {
        string x = find_par(a, parent);
        string y = find_par(b, parent);
        if (x == y)
            return;
        if (rank[x] == rank[y])
        {
            parent[x] = y;
            rank[y] += 1;
        }
        else if (rank[a] < rank[b])
        {
            parent[a] = b;
        }
        else
            parent[b] = a;
    }
  
  
  
  
  
  
  
    bool isSentenceSimilarity(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs)
    {
        if (words1.size() != words2.size())
            return false;

        map<string, int> rank;
        map<string, string> parent;
      
      
      
      
      
      
        for (auto it : pairs)
        {
            if (parent.find(it[0]) == parent.end())
            {
                parent[it[0]] = it[0];
                rank[it[0]] = 0;
            }

            if (parent.find(it[1]) == parent.end())
            {
                parent[it[1]] = it[1];
                rank[it[1]] = 0;
            }
        }
        for (auto it : pairs)
        {
            Union(it[0], it[1], rank, parent);
        }
      
      
      
      
      

        for (int i = 0; i < words1.size(); i++)
        {
            if(words1[i]==words2[i])
                continue;
            if (rank.find(words1[i]) == rank.end() || rank.find(words2[i]) == rank.end())
                return false;
            if (find_par(words1[i], parent) != find_par(words2[i], parent))
                return false;
        }
      
      
      
      
      
        return true;
      
      
    }
};
int main()
{

    int n;
    cin >> n;
    Solution s1;
    string s, b;
    vector<string> words1, words2;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        words1.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        words2.push_back(s);
    }
    int q;
    cin >> q;
    vector<vector<string>> pairs;
    while (q--)
    {
        cin >> s >> b;
        pairs.push_back({s, b});
    }
    cout << boolalpha<<s1.isSentenceSimilarity(words1, words2, pairs);
}

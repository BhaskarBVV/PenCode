// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

class Solution
{
public:
    bool comp(map<char, int> &a, map<char, int> &b)
    {
        map<char, int>::iterator it1, it2;
        it1 = a.begin(), it2 = b.begin();
        while (it1 != a.end() && it2 != b.end())
        {
            if (it1->second != it2->second || it1->first != it2->first)
                return false;
            it1++;
            it2++;
        }
        if (it1 == a.end() && it2 == b.end())
            return true;
        return false;
    }
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;

        map<char, int> pattern;
        for (auto it : s1)
            pattern[it]++;

        map<char, int> check;
        for (int i = 0; i < s1.size(); i++)
            check[s2[i]]++;

        if (comp(pattern, check))
            return true;

        int i = 0, j = s1.size();
        while (j < s2.size())
        {
            if (check[s2[i]] == 1)
                check.erase(s2[i]);
            else
                check[s2[i]]--;
            check[s2[j]]++;
            i++;
            j++;
            if (comp(pattern, check))
                return true;
        }
        return false;
    }
};

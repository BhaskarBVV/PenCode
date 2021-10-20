#include <bits/stdc++.h>
using namespace std;
string longestPalin(string s)
{
  // created a 2D matrix with boolean values, dp[i][j] is true if the string corressponding to the begin and end index is pallindrome.
  // start index is on left side and end index is on top side.
  // The entire leading diagonals corressponds to a particular gap between the characters of string.
  // All the subtstrings begin from first row, and column value is equal to j-th gap.
  // each substring ends at last column, hence j<s.size() is terminating condition.
  // In order to move diagonally, i.e to fill the next value corressponding to same gap move i->i+1 and j->j+1 (done in loop)
    bool dp[s.size()][s.size()];
    int st = 0, ed = -5, i, j, gap;
    for (gap = 0; gap <= s.size(); gap++)
    {
        for (i = 0, j = gap; j < s.size(); i++, j++)
        {
            if (gap == 0)
                dp[i][j] = true;
            else if (gap == 1)
            {
                if (s[i] == s[j])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else
            {
              // For all the subtstrings with gap > 1, just check their extreme values are same or not and check thier inner content from dp[][] table.
              // The inner content will be at diagonally left-down position of the current substring in dp[][] table. (i+1 for next row and j-1 for previous column)
                if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
          
            if (dp[i][j] && ed - st < j - i)
            {
              // considering the first Palindromic substring of particular length (of course it will be longest bcz each time we are moving ahead)
              // remove the condition (ed - st < j - i) to get the last Palindromic substring of particular length
                st = i;
                ed = j;
            }
        }
    }
    string str = "";
    for (int k = st; k <= ed; k++)
        str += s[k];
    return str;
}
int main()
{
    string s;
    cin >> s;
    cout << "The Longest substring palindrome" << longestPalin(s);
}


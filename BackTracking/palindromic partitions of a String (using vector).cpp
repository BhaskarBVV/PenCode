#include <iostream>
#include <vector>
#include <string>
using namespace std;
int is_pallindrome(string s)
{
    int i = 0, j = s.size() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
void solution(string str, vector<string> temp, vector<vector<string>> &res)
{
    if (str.size() == 0)
    {
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        string prefix = str.substr(0, i + 1);
        string remaining_str = str.substr(i + 1);
        if (is_pallindrome(prefix))
        {
            temp.push_back(prefix);
            solution(remaining_str, temp, res);
            temp.pop_back();
        }
    }
}
int main()
{
    string s;
    cin >> s;
    vector<vector<string>> res;
    vector<string> temp;
    solution(s, temp, res);
    for (auto it : res)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

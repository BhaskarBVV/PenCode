//EX s=aabccba, print-> abcba
#include <iostream>
#include <string>
//Bhaskar Varshney
using namespace std;
void print_unique(string &s, int st, char c)
{
    if (st == s.size())
        return;
    if (s[st] != c)
        cout << s[st];
    print_unique(s, st + 1, s[st]);
}
int main()
{
    string s;
    char c;
    cin >> s;
    c = s[0];
    cout << s[0];
    print_unique(s, 1, c);
}

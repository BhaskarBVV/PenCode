// 989abc  abdk78343
// 989 can be extracted but not 78343 from stringstream;
//all number in starting can be extracted.
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void Extract(string s)
{
    stringstream ss;
    ss << s;
    string temp;
    int num;
    while (!ss.eof())
    {
        ss >> temp;
        if (stringstream(temp) >> num)
        {
            cout << num << endl;
        }
        temp = "";
    }
}
int main()
{
    string s = "hello 7  98pm 88 977879overnight5656 lows will be in -90the -90 low 50 and 60 s";
    Extract(s);
}

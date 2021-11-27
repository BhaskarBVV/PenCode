#include <bits/stdc++.h>
#define ll long long int
using namespace std;
string intToStr(int num)
{
    ostringstream str1;
    str1 << num;
    return str1.str();
}
int strToInt(string x)
{
    stringstream temp(x);
    int num = 0;
    temp >> num;
    return num;
}
int main()
{
    int a;
    cin >> a;
    string z = intToStr(a);
    z += "BHASKAR";
    cout << z << endl;

    z = "1989";
    a = strToInt(z);
    cout << a + 2 << endl;
}

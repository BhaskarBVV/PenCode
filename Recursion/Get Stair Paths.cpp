//---------------------------------------------------------method 1-------------------------------
#include <bits/stdc++.h>
using namespace std;
void cnt(int n, vector<int> v)
{
    if (n == 0)
    {
        for (auto it : v)
            cout << it << " ";
        cout << endl;
        return;
    }
    if (n - 1 >= 0)
    {
        v.push_back(1);
        cnt(n - 1, v);
    }
    v.pop_back();
    if (n - 2 >= 0)
    {
        v.push_back(2);
        cnt(n - 2, v);
    }
    v.pop_back();
    if (n - 3 >= 0)
    {
        v.push_back(3);
        cnt(n - 3, v);
    }
    v.pop_back();
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    cnt(n, v);
}

//---------------------------------------------------------method 2-------------------------------
#include <bits/stdc++.h>
using namespace std;
void cnt(int n, vector<int> v, vector<vector<int>> &ans)
{
    if (n == 0)
    {
        ans.push_back(v);
        return;
    }
    if (n - 1 >= 0)
    {
        v.push_back(1);
        cnt(n - 1, v, ans);
    }
    v.pop_back();
    if (n - 2 >= 0)
    {
        v.push_back(2);
        cnt(n - 2, v, ans);
    }
    v.pop_back();
    if (n - 3 >= 0)
    {
        v.push_back(3);
        cnt(n - 3, v, ans);
    }
    v.pop_back();
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    vector<vector<int>> ans;
    cnt(n, v, ans);
    cout << "The ways are: ";
    for (auto it : ans)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
}
//---------------------------------------------------------method 3 without passing parameters-------------------------------
#include <bits/stdc++.h>
using namespace std;
vector<string> cnt(int n)
{
    if (n == 0)
    {
        vector<string> end;
        end.push_back("");
        return end;
    }
    vector<string> ans;
    if (n - 1 >= 0)
    {
        vector<string> a1 = cnt(n - 1);
        for (auto it : a1)
            ans.push_back(it + '1');
    }
    if (n - 2 >= 0)
    {
        vector<string> a1 = cnt(n - 2);
        for (auto it : a1)
            ans.push_back(it + '2');
    }
    if (n - 3 >= 0)
    {
        vector<string> a1 = cnt(n - 3);
        for (auto it : a1)
            ans.push_back(it + '3');
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> ans = cnt(n);
    cout << "The ways are: ";
    for (auto it : ans)
    {
        cout << it << endl;
    }
}

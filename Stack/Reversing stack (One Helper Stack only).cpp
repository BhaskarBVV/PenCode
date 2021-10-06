#include <bits/stdc++.h>
using namespace std;
stack<int> rev(stack<int> s)
{
    int size = s.size(), x, y, t;
    stack<int> s2;
    size -= 1;
    while (size--)
    {
        t = size + 1;
        x = s.top();
        s.pop();
        while (t--)
        {
            s2.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!s2.empty())
        {
            s.push(s2.top());
            s2.pop();
        }
        y -= 1;
    }
    return s;
}
int main()
{
    int n, i, x;
    stack<int> s, t;
    cout << "Enter the number of values : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        s.push(x);
    }
    t = s;
    cout << "\nStack before reversing\nTop->> ";
    while (!t.empty())
    {
        cout << t.top() << " ";
        t.pop();
    }
    cout << " <<-Bottom\n";
    cout << "\nStack after reversing\nTop->> ";
    t = rev(s);
    while (!t.empty())
    {
        cout << t.top() << " ";
        t.pop();
    }
    cout << " <<-Bottom";
}

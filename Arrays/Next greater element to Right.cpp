#include <iostream>
#include <stack>
//Bhaskar Varshney
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    int a[n];
    cout << "Enter the array : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[n];
    stack<int> s;
    int k = n - 2;
    b[n - 1] = -1;
    s.push(a[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < s.top())
        {
            b[k] = s.top();
            k -= 1;
            s.push(a[i]);
        }
        else
        {
            while (!s.empty() && a[i] > s.top())
            {
                s.pop();
            }
            if (s.empty())
                b[k] = -1;
            else
                b[k] = s.top();
            k -= 1;
            s.push(a[i]);
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " -> Nxt Gtr right -> " << b[i] << endl;
}

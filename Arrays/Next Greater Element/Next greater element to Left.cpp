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
    int k = 1;
    b[0] = -1;
    s.push(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] < s.top())
        {
            b[k] = s.top();
            k += 1;
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
            k += 1;
            s.push(a[i]);
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " -> Next Gtr Left -> " << b[i] << endl;
}

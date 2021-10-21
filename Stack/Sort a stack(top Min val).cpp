// Bhaskar Varshney
#include <iostream>
#include <stack>
using namespace std;
void insert_at_pos(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    if (s.top() > x)
    {
        s.push(x);
        return;
    }
    int y = s.top();
    s.pop();
    insert_at_pos(s, x);
    s.push(y);
}
void sort(stack<int> &s)
{
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    sort(s);
    insert_at_pos(s, x);
}
void print(stack<int> s)
{
    if (s.empty())
        return;
    cout << s.top() << " ";
    s.pop();
    print(s);
}
int main()
{
    //stack top will have max value
    stack<int> s;
    int x, a;
    cout << "Enter the no. of elements : ";
    cin >> x;
    cout << "Enter values : ";
    while (x--)
    {
        cin >> a;
        s.push(a);
    }
    cout << "\nStack before sorting is :\nTop->";
    print(s);
    cout << "<-Botton";
    sort(s);
    cout << "\nStack after sorting is :\nTop->";
    print(s);
    cout << "<-Botton";
}

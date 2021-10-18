#include <bits/stdc++.h>
using namespace std;
class _stack
{
    stack<int> s;
    int minEle;

public:
    int getMin()
    {
        if (s.empty())
            return -1;
        return minEle;
    }
    int pop()
    {
        if (s.empty())
        {
            cout << "Satck underflow";
            return -1;
        }
        int x = s.top();
        s.pop();
        if (x < minEle)
        {
            int temp = minEle;
            minEle = 2 * minEle - x;
            return temp;
        }
        return x;
    }
    void push(int x)
    {
        if (s.empty())
        {
            minEle = x;
            s.push(x);
        }
        else if (x >= minEle)
            s.push(x);
        else
        {
            s.push(x + x - minEle);
            minEle = x;
        }
    }
};
int main()
{
    _stack s;
    int ch = 1, choice;
    while (ch != 0)
    {
        cout << "1. to push.\n";
        cout << "2. to pop.\n";
        cout << "3. to getMin.\n";
        cin >> choice;
        if (choice == 1)
        {
            int x;
            cout << "Enter val : ";
            cin >> x;
            s.push(x);
        }
        else if (choice == 2)
        {
            int x = s.pop();
            cout << "popped value is : " << x;
        }
        else if (choice == 3)
        {
            int x = s.getMin();
            cout << "Min value in stack is : " << x;
        }
        cout << "\nDo you want to continue : (0 to exit)";
        cin >> ch;
    }
}

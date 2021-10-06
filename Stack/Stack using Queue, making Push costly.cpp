//Bhaskar Varshney
#include <bits/stdc++.h>
using namespace std;
//making push operation costly
class stk
{
private:
    queue<int> q1, q2;

public:
    void psh()
    {
        int x, z;
        cout << "Enter the value: ";
        cin >> x;
        q2.push(x);
        while (!q1.empty())
        {
            z = q1.front();
            q2.push(z);
            q1.pop();
        }
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void popp()
    {
        int x;
        if (q1.empty())
        {
            cout << "Stack already empty! \n";
            return;
        }
        q1.pop();
    }
    void print()
    {
        int x;
        q2 = q1;
        if (q1.empty())
        {
            cout << "Stack is empty! \n";
            return;
        }
        cout << "Top-> ";
        while (!q2.empty())
        {
            cout << q2.front() << " ";
            q2.pop();
        }
        cout << "<-Bottom\n";
    }
};
int main()
{
    int choice = 1, ch, x;
    stk s1;
    while (choice)
    {
        cout << "ENTER 1. to push in stack ";
        cout << "\nENTER 2. to pop from stack";
        cout << "\nENTER 3. to print stack.\nEnter choice: ";
        cin >> ch;
        if (ch == 1)
            s1.psh();
        else if (ch == 2)
            s1.popp();
        else if (ch == 3)
            s1.print();
        cout << "Do you want to continue (0/1) : ";
        cin >> choice;
    }
}

#include <bits/stdc++.h>
using namespace std;
class que
{
private:
    stack<int> s1, s2;

public:
    void psh()
    {
        int x, y;
        cout << "Enter the value: ";
        cin >> y;
        if (s1.empty())
        {
            s1.push(y);
            return;
        }
        else
        {
            while (!s1.empty())
            {
                x = s1.top();
                s2.push(x);
                s1.pop();
            }
            s2.push(y);
            while (!s2.empty())
            {
                x = s2.top();
                s1.push(x);
                s2.pop();
            }
        }
    }
    void popp()
    {
        if (s1.empty())
        {
            cout << "Queue is empty! \n";
            return;
        }
        s1.pop();
    }
    void print()
    {
        int x;
        if (s1.empty())
        {
            cout << "Queue is empty! \n";
            return;
        }
        s2 = s1;
        while (!s2.empty())
        {
            cout << s2.top() << " ";
            s2.pop();
        }
    }
};
int main()
{
    int choice = 1, ch, x;
    que q1;
    while (choice)
    {
        cout << "ENTER 1. to enqueue in queue";
        cout << "\nENTER 2. to dequeue in queue";
        cout << "\nENTER 3. to print queue.\nEnter choice: ";
        cin >> ch;
        if (ch == 1)
            q1.psh();
        else if (ch == 2)
            q1.popp();
        else if (ch == 3)
            q1.print();
        cout << "Do you want to continue (0/1) : ";
        cin >> choice;
    }
}

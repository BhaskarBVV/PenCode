#include <bits/stdc++.h>
using namespace std;
static void taskA()
{
    for (int i = 0; i < 10; i++)
        cout<< i << endl;
}
static void taskB()
{
    for (int i = 0; i < 10; i++)
        cout << i << endl;
}
int main()
{

    thread t1(taskA);
    thread t2(taskB);
    t1.join();
    t2.join();
    return 0;
}

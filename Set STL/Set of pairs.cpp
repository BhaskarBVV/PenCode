#include <set>
#include <iostream>
using namespace std;
class des_sort
{
public:
    bool operator()(pair<int, string> a, pair<int, string> b)
    {
        return a.first > b.first;
    }
};
int main()
{
    set<pair<int, string>> m;
    m.insert(make_pair(2, "A"));
    m.insert(make_pair(5, "B"));
    m.insert(make_pair(3, "A"));
    m.insert(make_pair(6, "D"));
    m.insert(make_pair(8, "C"));
    for (auto it : m)
        cout << it.first << " " << it.second << endl;

    cout << "---Values stored in set in descending order on basis of first value of pair -----\n";
    set<pair<int, string>, des_sort> m2;
    m2.insert(make_pair(2, "A"));
    m2.insert(make_pair(5, "B"));
    m2.insert(make_pair(3, "A"));
    m2.insert(make_pair(6, "D"));
    m2.insert(make_pair(8, "C"));
    for (auto it : m2)
        cout << it.first << " " << it.second << endl;
}

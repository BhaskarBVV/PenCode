#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> previousLargerElement(vector<int> &arr)
    {
        stack<int> stk;
        stk.push(*arr.rbegin());
        vector<int> ans(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++)
        {
            int current_number = arr[i];
            while (!stk.empty() && stk.top() <= current_number)
                stk.pop();
            if (!stk.empty())
                ans[i] = stk.top();
            stk.push(current_number);
        }
        return ans;
    }
};

class TestCase
{
public:
    vector<int> input;
    vector<int> expected;
    TestCase(vector<int> a, vector<int> b)
    {
        this->input = a;
        this->expected = b;
    }
};

bool are_equal(vector<int> a, vector<int> b)
{
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return false;
    return true;
}

int main()
{
    Solution s;
    vector<TestCase> test_cases;
    test_cases.push_back(TestCase({10, 4, 2, 20, 40, 12, 30}, {-1, 10, 4, -1, -1, 40, 40}));
    test_cases.push_back(TestCase({10, 20, 30, 40}, {-1, -1, -1, -1}));
    test_cases.push_back(TestCase({40, 30, 20, 10}, {-1, 40, 30, 20}));

    for (auto it : test_cases)
    {
        vector<int> ans = s.previousLargerElement(it.input);
        if (!are_equal(ans, it.expected))
        {
            cout << "Fail";
            break;
        }
    }
    cout << "PASS";
}

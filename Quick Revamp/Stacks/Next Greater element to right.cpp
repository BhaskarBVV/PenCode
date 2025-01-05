#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        stack<int> stk;
        stk.push(*arr.rbegin());
        vector<int> ans(arr.size(), -1);
        for (int i = arr.size() - 1; i >= 0; i--)
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
// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#

#include <bits/stdc++.h>
using namespace std;
class pairr
{
public:
    int val, idx;
    pairr()
    {
        val = 0;
        idx = 0;
    }
    pairr(int a, int b)
    {
        val = a;
        idx = b;
    }
};
pairr make_pairr(int a, int b)
{
    pairr p;
    p.val = a;
    p.idx = b;
    return p;
}
class Solution
{
public:
    vector<int> calculateSpan(int price[], int n)
    {
        stack<pairr> s;
        int nextLargerOnLeft[n];
        int k = 1;
        nextLargerOnLeft[0] = -1;
      
      // In nextLargerOnLeft we will be storing the index of next greater element to it on left in given array.
      // If there is no value larger than current value, we store -1
      // The span will be caluculted as -: (current_Index) - (Index_of_next_greater_element_on_left)
      
        s.push(make_pairr(price[0], 0));
        for (int i = 1; i < n; i++)
        {
            if (s.top().val > price[i])
            {
                nextLargerOnLeft[k] = s.top().idx;
                s.push(make_pairr(price[i], i));
                k++;
            }
            else
            {
                while (!s.empty() && price[i] >= s.top().val)
                    s.pop();
                if (s.empty())
                {
                    nextLargerOnLeft[k] = -1;
                    k++;
                    s.push(make_pairr(price[i], i));
                }
                else
                {
                    nextLargerOnLeft[k] = s.top().idx;
                    k++;
                    s.push(make_pairr(price[i], i));
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(i - nextLargerOnLeft[i]);
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Solution S1;
    vector<int> ans = S1.calculateSpan(a, n);
    for (auto it : ans)
        cout << it << " ";
}

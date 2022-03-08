// You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. 
// You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.

// You are restricted with the following rules:

// The division operator '/' represents real division, not integer division.
// For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
// Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
// For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
// You cannot concatenate numbers together
// For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
// Return true if you can get such expression that evaluates to 24, and false otherwise.

 

// Example 1:

// Input: cards = [4,1,8,7]
// Output: true
// Explanation: (8-4) * (7-1) = 24
// Example 2:

// Input: cards = [1,2,1,2]
// Output: false


#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<double> getValidOperations(double a, double b)
    {
        vector<double> ans;
        ans.push_back(a + b);
        ans.push_back(a * b);
        ans.push_back(a - b);
        ans.push_back(b - a);
        if (abs(a) > FLT_EPSILON)
            ans.push_back(b / a);
        if (abs(b) > FLT_EPSILON)
            ans.push_back(a / b);
        return ans;
    }

    bool isPossible(vector<double> &a)
    {
        if (a.size() == 1)
        {
            return abs(24.0 - a[0]) <= FLT_EPSILON;
        }

        for (int first_no = 0; first_no < a.size(); first_no++)
        {
            for (int sec_no = 0; sec_no < a.size(); sec_no++)
            {
                if (sec_no == first_no)
                    continue;
                double firstNumber = a[first_no];
                double secondNumber = a[sec_no];
                vector<double> res_of_Valid_operations = getValidOperations(firstNumber, secondNumber);
                vector<double> rem;
                for (double validOperation : res_of_Valid_operations)
                {
                    rem.clear();
                    rem.push_back(validOperation);
                    for (int i = 0; i < a.size(); i++)
                    {
                        if (i == first_no && i == sec_no)
                            continue;
                        rem.push_back(a[i]);
                    }
                    if (isPossible(rem))
                        return true;
                }
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int> &cards)
    {
        vector<double> card(cards.begin(), cards.end());
        return isPossible(card);
    }
};


 

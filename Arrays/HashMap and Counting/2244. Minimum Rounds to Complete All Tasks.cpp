// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        map<int, int> taskTypeCounter;
        for (auto it : tasks)
        {
            taskTypeCounter[it] += 1;
        }
        int rounds = 0;
        for (auto it : taskTypeCounter)
        {
            int count = it.second;
            if (count == 1)
                return -1;

            // In each round we will try to do 3 tasks, but if total remaining tasks are not divisilble by 3,
            // We will try to complete 2 tasks one by one, until remaining tasks can be done in group of 3.
            // This way we can minimize the number of rounds.
            while (count % 3 != 0 && count > 0)
            {
                rounds += 1;
                count -= 2;
            }
            if (count > 0)
            {
                rounds += count / 3;
            }
        }
        return rounds;
    }
};
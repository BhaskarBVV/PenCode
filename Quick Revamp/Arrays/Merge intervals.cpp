// https://leetcode.com/problems/merge-intervals/description/

class Solution
{
    bool can_be_merged(vector<int> head, vector<int> current)
    {
        // current interval start point should lie inside the head pointed interval
        return (head[0] <= current[0] && current[0] <= head[1]);
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Ask will the intervals will be provided in sorted order or not.
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        // interpret this as a pointer based approach, where the head pointer will go to each interval,
        // and will check if the current interval can be merged or not.
        vector<int> head = intervals[0];
        for (auto it : intervals)
        {
            if (can_be_merged(head, it))
            {
                head[1] = max(head[1], it[1]);
            }
            else
            {
                ans.push_back(head);
                head = it;
            }
        }
        ans.push_back(head);
        return ans;
    }
};

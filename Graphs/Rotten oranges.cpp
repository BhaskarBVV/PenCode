// Just similar to level order traversal of tree with \n.

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &a)
    {
        queue<pair<int, int>> q;
        int fresh = 0, rot = 0;
        int n = a.size(), m = a[0].size(), time = 0, i, j;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[0].size(); j++)
            {
                if (a[i][j] == 2)
                {
                    rot++;
                    q.push({i, j});
                }
                else if (a[i][j] == 1)
                    fresh++;
            }
        }
        if (fresh == 0)
            return 0;
        if (rot == 0)
            return -1;
        q.push({-1, -1});
        pair<int, int> p;
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            if (p.first == -1)
            {
                time++;
                if (!q.empty())
                    q.push({-1, -1});
            }
            else
            {
                i = p.first;
                j = p.second;
                if (i + 1 < n && a[i + 1][j] == 1)
                {
                    a[i + 1][j] = 2;
                    q.push({i + 1, j});
                }
                if (i - 1 >= 0 && a[i - 1][j] == 1)
                {
                    a[i - 1][j] = 2;
                    q.push({i - 1, j});
                }
                if (j + 1 < m && a[i][j + 1] == 1)
                {
                    a[i][j + 1] = 2;
                    q.push({i, j + 1});
                }
                if (j - 1 >= 0 && a[i][j - 1] == 1)
                {
                    a[i][j - 1] = 2;
                    q.push({i, j - 1});
                }
            }
        }
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[0].size(); j++)
            {
                if (a[i][j] == 1)
                    return -1;
            }
        }
        return time - 1;
    }
};

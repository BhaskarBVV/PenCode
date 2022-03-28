class Solution
{
public:
    void helper(vector<vector<int>> &a, int i, int j, string s, vector<string> &v, vector<vector<bool>> &vis)
    {
        int n = a.size();
        if (i < 0 || i >= n || j < 0 || j >= n || a[i][j] == 0 || vis[i][j] == true)
            return;
        if (i == n - 1 && j == n - 1)
        {
            v.push_back(s);
            return;
        }
        vis[i][j] = true;
        helper(a, i + 1, j, s + 'D', v, vis);
        helper(a, i, j + 1, s + 'R', v, vis);
        helper(a, i - 1, j, s + 'U', v, vis);
        helper(a, i, j - 1, s + 'L', v, vis);
        vis[i][j] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        string s;
        vector<string> v;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        helper(m, 0, 0, s, v, vis);
        return v;
    }
};

// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

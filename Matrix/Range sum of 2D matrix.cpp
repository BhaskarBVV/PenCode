class NumMatrix
{
public:
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>> &matrix)
    {
        a = matrix;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 1; j < a[0].size(); j++)
            {
                a[i][j] += a[i][j - 1];
            }
        }
        for (int i = 0; i < a[0].size(); i++)
        {
            for (int j = 1; j < a.size(); j++)
            {
                a[j][i] += a[j - 1][i];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int left = 0, top = 0, dia = 0;
        if (row1 - 1 >= 0)
            top = a[row1 - 1][col2];
        if (col1 - 1 >= 0)
            left = a[row2][col1 - 1];
        if (row1 - 1 >= 0 && col1 - 1 >= 0)
            dia = a[row1 - 1][col1 - 1];
        return a[row2][col2] - left - top + dia;
    }
};

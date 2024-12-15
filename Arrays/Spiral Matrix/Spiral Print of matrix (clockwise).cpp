#include <iostream>
#include <vector>
using namespace std;
void spiralOrder(vector<vector<int>> &a)
{
    int sr = 0, er = a.size() - 1, sc = 0, ec = a[0].size() - 1, i;
    while (sr <= er && sc <= ec)
    {
        for (i = sc; i <= ec; i++)
            cout << a[sr][i] << " ";
        sr += 1;
        for (i = sr; i <= er; i++)
            cout << a[i][ec] << " ";
        ec -= 1;
        if (er >= sr)
        {
            for (i = ec; i >= sc; i--)
                cout << a[er][i] << " ";
            er -= 1;
        }
        if (ec >= sc)
        {
            for (i = er; i >= sr; i--)
                cout << a[i][sc] << " ";
            sc += 1;
        }
    }
}
int main()
{
    int n, m;
    cout << "Enter the no. of rows : ";
    cin >> n;
    cout << "Enter the no. of columns : ";
    cin >> m;
    cout << "\nEnter matrix row wise : \n";
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << "Spiral print : ";
    spiralOrder(v);
}

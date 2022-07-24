// https://leetcode.com/problems/regions-cut-by-slashes/

// Note:  The cell number will be (row*n)+col;
// 		   Each cell will be divided into four parts(a,b,c,d).
// 		   ___________
// 		   | \  a  / |
// 		   |   \  /  |
// 		   | d /  \ b|
// 		   | /  c  \ |
// 		   -----------
		   
// 		   Each cell part a will be Unioned with part C of above cell.
// 		   Each cell part b will be Unioned with part D of right cell.
// 		   Each cell part c will be Unioned with part A of below cell.
// 		   Each cell part d will be Unioned with part B of left cell.
		   
// 		   If "/" type of slash is present, then A,D will be Unioned and B,C will be Unioned.
// 		   if "\" type of slash is present then A,B will be Unioned and D,C will be unioned.
// 		   If the cell is empty, then all A,B,C,D will be unioned.
		   
// 		   In the end, perform the find_par() on every part of evey cell, inorder to find their Top most parent (The top most parent is one which is the leader of entire set.)
	
// 		   The number of distinct parents will be the number of Regions.


class Solution
{
public:
  
  
  
    int find_par(int a, vector<int> &parent)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find_par(parent[a], parent);
    }
  
  
  
  
  
    void Union(int x, int y, vector<int> &parents, vector<int> &rank)
    {
        int a = find_par(x, parents);
        int b = find_par(y, parents);
		
        if (rank[a] == rank[b])
        {
            parents[a] = b;
            rank[b] += 1;
        }
        else if (rank[a] < rank[b])
            parents[a] = b;
        else
            parents[b] = a;
    }
  
  
  
  
  
  
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size(), m = grid[0].size(), inner_cells, cell_no;
        inner_cells = n * m * 4;
      
      
      
        vector<int> parent;
        vector<int> rank(inner_cells, 0);
        for (int i = 0; i < inner_cells; i++)
            parent.push_back(i);

      
      
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
              
              
                cell_no = n * i + j;
              
              
              
                int a = cell_no * 4;
                int b = cell_no * 4 + 1;
                int c = cell_no * 4 + 2;
                int d = cell_no * 4 + 3;

              
              
                if (i - 1 >= 0)
                    Union(a, (n * (i - 1) + j) * 4 + 2, parent, rank);

                if (j - 1 >= 0)
                    Union(d, (n * i + (j - 1)) * 4 + 1, parent, rank);

                if (i + 1 < n)
                    Union(c, (n * (i + 1) + j) * 4 + 0, parent, rank);

                if (j + 1 < m)
                    Union(b, (n * i + (j + 1)) * 4 + 3, parent, rank);

              
              
              
                if (grid[i][j] == '/')
                {
                    Union(a, d, parent, rank);
                    Union(b, c, parent, rank);
                }
                else if (grid[i][j] == '\\')
                {
                    Union(a, b, parent, rank);
                    Union(c, d, parent, rank);
                }
                else
                {
                    Union(a, b, parent, rank);
                    Union(c, b, parent, rank);
                    Union(c, d, parent, rank);
                    Union(a, d, parent, rank);
                }
            }
        }
      
      
      
      
        set<int> ans;
        for (int i = 0; i < inner_cells; i++)
            parent[i] = find_par(i, parent);
        for (auto it : parent)
            ans.insert(it);
      
      
      
        return ans.size();
    }
};

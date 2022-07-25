class Solution
{
public:
  
  
  
    void Union(int a, int b, vector<int> &parent, vector<int> &rank)
    {
        int LeadA = find_par(a, parent);
        int LeadB = find_par(b, parent);
        
        if (rank[LeadB] == rank[LeadB])
        {
            parent[LeadB] = LeadA;
            rank[LeadA] += 1;
        }
        else if (rank[LeadA] < parent[LeadB])
        {
            parent[LeadA] = LeadB;
        }
        else
            parent[LeadB] = LeadA;
    }
  
  
  

    int find_par(int a, vector<int> &parent)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find_par(parent[a], parent);
    }
  
  
  
  
  

    bool equationsPossible(vector<string> &equations)
    {
        vector<int> parent;
        for (int i = 0; i < 26; i++)
            parent.push_back(i);
      
        vector<int> rank(26, 0);
        vector<string> equations_with_NotEqual;
      
      
        for (auto it : equations)
        {
            if (it[1] == '!')
                equations_with_NotEqual.push_back(it);

            else
                Union(it[0] - 'a', it[3] - 'a', parent, rank);
        }

      
      
        for (auto it : equations_with_NotEqual)
        {
            if (find_par(it[0] - 'a', parent) == find_par(it[3] - 'a', parent))
                return false;
        }
      
      
      
        return true;
    }
};

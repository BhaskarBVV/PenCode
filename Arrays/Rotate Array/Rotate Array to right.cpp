class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n=a.size();
        k=k%n;
        int i=0,j=n-k-1;
        while(i<j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
        i=n-k,j=n-1;
        while(i<j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
        i=0,j=n-1;
        while(i<j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
};



// OR



class Solution {
public:
    void rotate(vector<int>& a, int k)
    {
        int n=a.size();
        k=k%n;
        reverse(a.begin(),a.begin()+n-k);
        reverse(a.begin()+n-k,a.end());
        reverse(a.begin(),a.end());
    }
};


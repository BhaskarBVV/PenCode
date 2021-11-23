class Solution{
	public:
	vector<int>AllPrimeFactors(int n) 
	{
	   int flag=1;
	   vector<int>v;
	   for(int i=2;i*i<=n;i++)
	   {
	       flag=1;
	       while(n%i==0)
	       {
	           flag=0;
	           n/=i;
	       }
	       if(flag==0)
	       v.push_back(i);
	   }
	   if(n!=1)
	   v.push_back(n);
	   return v;
	}
};

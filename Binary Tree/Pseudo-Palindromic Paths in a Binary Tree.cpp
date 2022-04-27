class Solution
{
public:
    void dfs(TreeNode *root, int &cnt, int odd, map<int, int>&mp)
    {
        if (root == NULL)
        {
            return;
        }
		// checking for the count of that number
		// for making a plaindrome, only <=1 number should have odd counts, while all other should be present even number of times.
        if (mp[root->val] == 0)
        {
            odd++;
        }
        else if (mp[root->val] % 2 != 0)
            odd--;
        else
            odd++;
        mp[root->val]++;
        if (root->left == NULL && root->right == NULL)
        {
		// check for leaf node from here only
		// don't check for odds in block where root==NULL, bcz leaf node will make two calls
		// i.e. one to left and other to right, and your answer will get twice.
            if (odd <= 1)
                cnt++;
        }
        dfs(root->left, cnt, odd, mp);
        dfs(root->right, cnt, odd, mp);
        mp[root->val]-=1; // MUST REDUCE THE COUNT, BCZ WE'VE SEND THE MAP BY reference, not odd variable.
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int cnt = 0, odd = 0;
        map<int, int> mp;
        dfs(root, cnt, odd, mp);
        return cnt;
    }
};

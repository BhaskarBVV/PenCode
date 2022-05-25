// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.

// https://leetcode.com/problems/path-sum-iii/
  
class Solution
{
public:
    void helper(TreeNode *root, int &ans, map<long long int,long long int>&mp, long long int sum, int &target)
    {
        if (root == NULL)
            return;
      
        sum += root->val;
      
        if (mp.find(sum-target) != mp.end())
            ans+=mp[sum-target];
        mp[sum]++;
      
        helper(root->left, ans, mp, sum, target);
        helper(root->right, ans, mp, sum, target);
      
        mp[sum]--;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        map<long long int, long long int> mp;
      
        mp[0]++;
      
        int ans = 0;
        helper(root, ans, mp, (long long int)0, targetSum);
        return ans;
    }
};

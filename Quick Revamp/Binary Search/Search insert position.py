# https://leetcode.com/problems/search-insert-position/

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)-1
        ans = len(nums)
        while left<=right:
            mid = left + (right-left)//2
            if nums[mid] < target:
                left = mid+1
            else:
                ans = mid # because agar number present hai to wahi position chaiye, verna usse badi
                right = mid-1
        return ans

# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution:

    def __init__(self):
        self.min = 5001

    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums)-1
        while left <= right:
            mid = left + (right-left)//2

          # Identify the sorted half and compare the first element of that half with the minimum value.
          # Now, since we have identified the minimum value of this half, we can eleminate this half. And, can continue searching on other half.
            if nums[left] <= nums[mid]:
                self.min = min(nums[left], self.min)
                left = mid+1
            elif nums[mid] <= nums[right]:
                self.min = min(nums[mid], self.min)
                right = mid-1
        return self.min

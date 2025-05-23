# https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution:
    
    def __first_occurence(nums, target):
        left = 0
        right = len(nums)-1
        ans = -1
        while left <= right:
            mid = left + (right-left)//2
            if nums[mid] == target:
                ans = mid
                right = mid-1
            elif nums[mid] < target:
                left = mid+1
            else:
                right = mid-1
        return ans
    
    def __last_occurence(nums, target):
        left = 0
        right = len(nums)-1
        ans = -1
        while left<=right:
            mid = left + (right-left)//2
            if nums[mid] == target:
                ans = mid
                left = mid+1
            elif nums[mid] < target:
                left = mid+1
            else:
                right = mid-1
        return ans

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first_occurence = Solution.__first_occurence(nums, target)
        if first_occurence == -1:
            return [-1,-1]
        last_occurence = Solution.__last_occurence(nums, target)
        return [first_occurence, last_occurence]

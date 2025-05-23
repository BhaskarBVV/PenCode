# https://leetcode.com/problems/search-in-rotated-sorted-array/

## "Identify the sorted half" — 
# First, figure out which half of the array is already sorted. This is important because searching in a sorted section is easier.

## "Now that we've found the sorted half, check if the target is in that sorted range." — 
# After identifying which half is sorted, see if the number you're looking for (the target) lies within that sorted portion.

## "If it is in the sorted half, eliminate the other half and continue searching in the sorted part." — 
# If the target number is inside the sorted half, you can safely ignore the other half and continue searching only in the sorted side.

## "But if the target is not in the sorted half, eliminate the sorted half and search in the other half using binary search." — 
# If the target is not in the sorted half, it must be in the unsorted half, so now ignore the sorted part and do the search in the remaining half.

class Solution:

    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)-1
        while left<=right:
            mid = left + (right-left)//2
            if nums[mid] == target:
                return mid
           
            if nums[left] <= nums[mid]: # Check is left half sorted?
                if nums[left] <= target and target <= nums[mid]: # if target lies in this left sorted half
                    right = mid-1 # elemiate the right half
                else:
                    left = mid+1 # eleminate the left half
            elif nums[mid+1] <= nums[right]: # Check is right half sorted?
                if nums[mid+1] <= target and target <= nums[right]: # if target lies in this right sorted half
                    left = mid+1 # eleminate the left half
                else:
                    right = mid-1 # elemiate the right half
        return -1

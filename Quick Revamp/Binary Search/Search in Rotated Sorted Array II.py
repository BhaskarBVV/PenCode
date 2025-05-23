# https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

# 1. Look at the middle of the current range.
# 2. Check:
# If the mid value is the target → found it!
# If nums[left], nums[mid], and nums[right] are all the same, just skip the edges (left++, right--). This avoids getting stuck due to duplicates.
# If left to mid is sorted: check if the target is in that range. If yes, search there. If not, search the other half.
# Otherwise, the right half is sorted. Use the same idea.

#---------------------------------------------------------------------------------------------------------------------------------------------------

# Why that if nums[left] == nums[mid] == nums[right] is important:
# In arrays with duplicates, we can't always tell which half is sorted.
# So when values at left, mid, and right are all the same, we just shrink the search window — it helps us avoid infinite loops or wrong decisions.

#---------------------------------------------------------------------------------------------------------------------------------------------------

# Example: nums = [1, 0, 1, 1, 1], target = 0
# Start: left = 0, right = 4, so mid = 2
# nums[mid] = 1, nums[left] = 1, nums[right] = 1
# All same → can't decide the sorted part → do left++ and right--

# Now: left = 1, right = 3, mid = 2
# nums[mid] = 1, nums[left] = 0, nums[right] = 1
# Left to mid (0 to 1) is sorted
# Is target = 0 in this range? Yes → search left side

# Adjust right = mid - 1 = 1

# Now: left = 1, right = 1, mid = 1
# nums[mid] = 0 → found it → return True

#---------------------------------------------------------------------------------------------------------------------------------------------------

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        left = 0
        right = len(nums)-1
        while left <= right:
            mid = left + (right-left)//2
            if nums[mid] == target:
                return True
            elif nums[left] == nums[mid] and nums[mid] == nums[right]:
                left += 1
                right -= 1
            elif nums[left] <= nums[mid]:
                if nums[left] <= target and target <= nums[mid]:
                    right = mid-1
                else:
                    left = mid+1
            elif nums[mid+1] <= nums[right]:
                if nums[mid+1] <= target and target <= nums[right]:
                    left = mid+1
                else:
                    right = mid-1
        return False

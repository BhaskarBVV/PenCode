# https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        update_position = 0
        excluded = 0
        # Start filling the same array again from start.
        # if same number has been written 2 times, don't write the same number again, instead count this number as excluded from the final array.
        # After updating entire array, we need to return the length of our array that contain at most 2 duplicates of each number (that is, the lenght of our array after removing duplicates).
        # For this, the result will be the length of given array - excluded elements, because the excluded numbers are the only one which will not be th part of final array.
        for i in range(len(nums)):
            if update_position-2 >= 0 and nums[i] == nums[update_position-2]:
                excluded += 1
                continue
            nums[update_position] = nums[i]
            update_position += 1

        return len(nums) - excluded

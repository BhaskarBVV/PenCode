# https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        update_position = 0
        excluded = 0
        for i in range(len(nums)):
            if update_position-2 >= 0 and nums[i] == nums[update_position-2]:
                excluded += 1
                continue
            nums[update_position] = nums[i]
            update_position += 1

        return len(nums) - excluded

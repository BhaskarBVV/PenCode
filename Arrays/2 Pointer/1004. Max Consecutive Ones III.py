# https://leetcode.com/problems/max-consecutive-ones-iii/

# Similar to longest substring without repeating characters.
# start iterating from the begining of the string, if you encounter 0, than check if you have chances remaining to swap 0 to 1.
# If yes, then include that zero in your longest string, increase the max_lenght
# If no, then start you another pointer until you discover another zero, and exclude it from your answer,
# as now you will have 1 chance again to flip current 0

from typing import List


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        i, j = 0, 0
        flips = 0
        max_len = 0
        while j < len(nums):
            if nums[j] == 1:
                max_len = max(max_len, j - i + 1)
                j += 1
            elif nums[j] == 0 and flips != k:
                max_len = max(max_len, j - i + 1)
                flips += 1
                j += 1
                continue
            elif nums[j] == 0 and flips == k:
                while nums[i] != 0:
                    i += 1
                i += 1
                flip -= 1
        return max_len

# https://leetcode.com/problems/sort-colors/description/
# Explanation: https://leetcode.com/problems/sort-colors/solutions/6133553/on-100-faster/

from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:

        i, j, k = 0, 0, len(nums)-1
        while j <= k:  # we need <= because, see this case: [2,0,1].
            if nums[j] == 0 and i != j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
            elif nums[j] == 2 and j != k:
                nums[j], nums[k] = nums[k], nums[j]
                k -= 1
            else:
                j += 1

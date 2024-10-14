# https://leetcode.com/problems/4sum/description/

from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        nums.sort()
        
        for i in range(len(nums)-1):
            if i>0 and nums[i]==nums[i-1]: # jis index se loop start hoga usi ke aage wali values se check krna hai for duplicate
                continue
            for j in range(i+1, len(nums)-1): # jis index se loop start hoga usi ke aage wali values se check krna hai for duplicate
                if j>i+1 and nums[j] == nums[j-1]:
                    continue
                remaining_sum = target - (nums[i]+nums[j])

                left = j+1
                right = len(nums)-1
                while left < right:
                    sum = nums[left] + nums[right]

                    if sum == remaining_sum:
                        ans.append([nums[i], nums[j], nums[left], nums[right]])
                        while left < right and nums[left] == nums[left+1]:
                            left+=1
                        while left < right and nums[right] == nums[right-1]:
                            right-=1
                        left += 1
                        right -= 1
                    elif sum < remaining_sum:
                        left += 1
                    else:
                        right -= 1
        return ans



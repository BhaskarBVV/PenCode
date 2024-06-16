def lower_bound(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        middle = 0
        ans = len(nums)
        while left <= right:
            middle = left + ((right - left) // 2)
            if nums[middle] >= target:
                right = middle - 1
                ans = middle
            elif nums[middle] < target:
                left = middle + 1
        return ans

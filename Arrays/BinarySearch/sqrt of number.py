class Solution:
    def mySqrt(self, x: int) -> int:
        left = 1
        right = x
        middle = 1
        ans = 0
        while left <= right:
            middle = left + (right - left) // 2
            if middle * middle <= x:
                ans = middle
                left = middle + 1
            elif middle * middle > x:
                right = middle - 1
        return ans

# https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

from typing import List

class Solution:

    @staticmethod
    def can_be_merged(interval_a, interval_b):
        return interval_a[1] >= interval_b[0]

    @staticmethod
    def update_intersecting_interval(interval_a, interval_b):
        a, b = interval_a
        c, d = interval_b
        start = max(a, c)
        end = min(b, d)
        updated_interval = [start, end]
        return updated_interval

    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        arrows_count = 1
        current_interval = points[0]
        for _ in range(1, len(points)):
            is_intersecting_interval = Solution.can_be_merged(current_interval, points[_])
            if is_intersecting_interval:
                current_interval = Solution.update_intersecting_interval(current_interval, points[_])
            else:
                arrows_count += 1
                current_interval = points[_]

        return arrows_count

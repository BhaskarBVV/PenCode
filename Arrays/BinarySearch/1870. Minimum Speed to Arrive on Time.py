# https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

# Note: Every train will depart at integer hour
# Example: if the train speed is 5 and distance is 1, than time = 1/5 = 0.2.
# The next train will be an integer hour, so we will have to wait for next 0.8 minutes.
# As a result the time taken in current train is ceil(1/5)
# For binary search max value, we can take total distance / total provided time.    
from typing import List
import math

class Solution:
    
    def can_reach_in_time(self, distances, time, speed):
        time_taken = 0
        for index in range(len(distances)):
            distance = distances[index]
            if index == len(distances)-1:
                time_taken += distance/speed
            else:
                time_taken += math.ceil(distance/speed)            
        if time_taken>time:
            return False
        return True

    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        MAX_INT_VALUE = 9999999999
        min_speed = 1
        max_speed = 10000000
        ans = MAX_INT_VALUE
        while min_speed <= max_speed:
            middle = min_speed + (max_speed - min_speed)//2
            if self.can_reach_in_time(dist, hour, middle):
                ans = min(ans, middle)
                max_speed = middle - 1
            else:
                min_speed = middle + 1
        return -1 if ans == MAX_INT_VALUE else ans
from typing import List
import math

class Solution:
    
    def can_finish_bananas(self, piles, time, speed):        
        for bananas in piles:        
            time_taken = math.ceil(bananas/speed)            
            time -= time_taken            
            if time < 0:                
                return False
        if time >=0:
            return True

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        min_speed = 1
        max_speed = max(piles)
        ans = 9999999999999
        while min_speed <= max_speed:
            middle = min_speed + (max_speed - min_speed)//2
            if self.can_finish_bananas(piles, h, middle):
                ans = min(ans, middle)
                max_speed = middle - 1                
            else:
                min_speed = middle + 1
        return ans

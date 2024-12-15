# https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

from typing import List

class Solution:

    def can_distribute_all(self, candies_pile, pile_size_alloted_to_child, children):
        for pile in candies_pile:
            children -= pile//pile_size_alloted_to_child
            if children<=0:
                return True
        return False

    def maximumCandies(self, candies: List[int], k: int) -> int:
        each_pile_max_length = max(candies)
        each_pile_min_length = 1
        ans = 0
        while each_pile_min_length <= each_pile_max_length:
            middle = each_pile_min_length + (each_pile_max_length - each_pile_min_length)//2
            if self.can_distribute_all(candies, middle, k):
                ans = max(ans, middle)
                each_pile_min_length = middle +1
            else:
                each_pile_max_length = middle -1
        return ans

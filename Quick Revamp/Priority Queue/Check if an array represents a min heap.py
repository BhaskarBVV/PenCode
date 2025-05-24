class Solution:
    def isHeap(self, nums):
        for index in range(len(nums)):
            heap_len = len(nums)
            left_child_index = 2*index+1
            right_child_index = 2*index+2
            if left_child_index < heap_len and nums[left_child_index]<nums[index]:
                return False
            if right_child_index < heap_len and nums[right_child_index]<nums[index]:
                return False
        return True

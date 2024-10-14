# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        character_count ={}
        max_len = 0
        left = 0
        right = 0
        while right<len(s):
            if character_count.get(s[right], 0) == 0:
                max_len = max(max_len,right-left+1)
                character_count[s[right]] = 1
                right+=1
            else:
                while character_count.get(s[right])!=0 and left < len(s)-1:
                    character_count[s[left]] = 0
                    left+=1
        return max_len

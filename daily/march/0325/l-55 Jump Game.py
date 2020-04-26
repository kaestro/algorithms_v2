from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxPos = 0
        for i in range(len(nums)):
            if maxPos < i: return False
            maxPos = max(maxPos, i + nums[i])
        return True
    
    def canJump_backwards(self, nums: List[int]) -> bool:
        maxPos = len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            if i + nums[i] >= maxPos:
                maxPos = i
        return maxPos == 0

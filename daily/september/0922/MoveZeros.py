# https://leetcode.com/problems/move-zeroes/
# algorithm: array
# 09.22.2020

from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        nonZeroIdx = -1
        for idx, num in enumerate(nums):
            if num != 0:
                nonZeroIdx += 1
                nums[idx] = nums[nonZeroIdx]
                nums[nonZeroIdx] = num

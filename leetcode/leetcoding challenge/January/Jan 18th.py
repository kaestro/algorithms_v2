from typing import List


class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        i, j = 0, len(nums)-1
        ans = 0
        while i < j:
            sum = nums[i] + nums[j]
            if sum == k:
                ans += 1
                i += 1
                j -= 1
            elif sum > k:
                j -= 1
            else:
                i += 1
        return ans
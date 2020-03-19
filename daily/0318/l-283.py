from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        zerocnt = 0
        for val in nums:
            if val == 0:
                zerocnt += 1
        for _ in range(zerocnt):
            nums.remove(0)
            nums.append(0)

    # nonzero idx doesn't go forward if it is zero. that is, where the last nonzeroidx
    # should belong to
    def betterMoveZeros(self, nums: List[int]) -> None:
        lastNonzeroIdx = -1

        for i, num in enumerate(nums):
            if num != 0:
                lastNonzeroIdx += 1
                nums[i], nums[lastNonzeroIdx] = nums[lastNonzeroIdx], nums[i]
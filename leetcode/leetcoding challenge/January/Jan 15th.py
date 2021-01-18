from typing import List


class Solution:
    def minOperations(self, nums: List[int], limit: int) -> int:
        leftEnd = 0
        pref = 0
        while leftEnd < len(nums):
            pref += nums[leftEnd]
            if pref >= limit:
                break
            leftEnd += 1
        
        if leftEnd == len(nums):
            return -1
        
        if pref == limit:
            ans = leftEnd + 1
        else:
            ans = float('inf')
        
        rightStart = len(nums)
        ## how to deal with the case where pref < limit but rightStart == leftEnd?
        ## -> already dealt at front: line 14
        while leftEnd >= 0:
            pref -= nums[leftEnd]
            leftEnd -= 1
            
            while pref < limit and rightStart > leftEnd:
                rightStart -= 1
                pref += nums[rightStart]
            
            if pref == limit:
                ans = min(ans, leftEnd + 1 + len(nums) - rightStart)

        return -1 if ans == float('inf') else ans



if __name__ == "__main__":
    nums = [1,1,4,2,3]
    limit = 5
    sol = Solution()
    sol.minOperations(nums, limit)
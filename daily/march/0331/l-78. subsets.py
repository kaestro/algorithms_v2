from typing import List

class Solution:
    def __init__(self):
        self.ss = [[]]


    def subsets(self, nums: List[int]) -> List[List[int]]:
        if not nums: return [[]]
        self.helper(nums, [], 0)
        return self.ss
    

    def helper(self, nums: List[int], prev: List[int], idx: int):
        if idx == len(nums): return
        self.helper(nums, prev, idx+1)
        cur = prev.copy()
        cur.append(nums[idx])
        self.ss.append(cur)
        self.helper(nums, cur, idx+1)

if __name__ == "__main__":
    nums = [1,2,3]
    S = Solution()

    print(S.subsets(nums))
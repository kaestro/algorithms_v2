import collections

class Solution(object):
    def singleNumber(self, nums):
        numsCnt = collections.Counter(nums)
        for (key, val) in numsCnt.items():
            if val == 1: ans = key
        return ans


if __name__ == "__main__":
    nums = [2,2,1]
    S = Solution()
    S.singleNumber(nums)
import collections
from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        topk = collections.Counter(nums).most_common(k)
        return [num[0] for num in topk]

if __name__ == "__main__":
    nums = [1,1,1,2,2,3]
    k = 2

    print(Solution().topKFrequent(nums, k))
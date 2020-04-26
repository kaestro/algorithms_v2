from typing import List
import collections


class Solution:
    def countElements(self, arr: List[int]) -> int:
        cnt = collections.Counter(arr)

        res = 0
        for key, val in cnt.items():
            if key - 1 in cnt:
                res += val
        
        return res


if __name__ == "__main__":
    arr = [1,2,3]
    S = Solution()
    S.countElements(arr)


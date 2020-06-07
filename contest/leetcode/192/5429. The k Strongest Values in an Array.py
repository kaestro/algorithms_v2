from typing import List

class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        arrlen = len(arr)
        median = arr[(arrlen - 1) // 2]
        
        powers = []
        for val in arr:
            powers.append((abs(val - median), val))
        
        ans = []
        for val in sorted(powers, key = lambda x: (x[0], x[1]), reverse = True):
            ans.append(val[1])
            k -= 1
            if k == 0:
                break
        return ans


if __name__ == "__main__":
    arr = [1,2,3,4,5]
    k = 2
    S = Solution()
    arr = [1,1,3,5,5]
    k = 2
    print(S.getStrongest(arr, k))

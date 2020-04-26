import collections
from typing import List
import queue
import itertools

class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        numLen = len(nums)
        if numLen == 0: return True

        num_cnts = collections.Counter(nums)
        tails = collections.defaultdict(int)

        for num in nums:
            if num_cnts[num] == 0: continue

            num_cnts[num] -= 1

            if tails[num-1] > 0:
                tails[num-1] -= 1
                tails[num] += 1
            elif num_cnts[num+1] * num_cnts[num+2] > 0:
                num_cnts[num+1] -= 1
                num_cnts[num+2] -= 1
                tails[num+2] += 1
            else:
                return False
        return True
    
    def isPossible2(self, nums: List[int]) -> bool:
        headsQ = queue.Queue()

        prevNum, prevCnt = None, 0

        for (curNum, grp) in itertools.groupby(nums):
            curCnt = len(list(grp))

            if prevNum is None:
                for _ in range(curCnt):
                    headsQ.put(curNum)
            
            elif curNum > prevNum + 1:
                for _ in range(prevCnt):
                    if headsQ.empty() or headsQ.get() > prevNum - 2:
                        return False
                for _ in range(curCnt):
                    headsQ.put(curNum)
            
            elif curNum == prevNum + 1:
                if curCnt > prevCnt:
                    for _ in range(curCnt - prevCnt):
                        headsQ.put(curNum)
                elif curCnt < prevCnt:
                    for _ in range(prevCnt - curCnt):
                        if headsQ.empty() or headsQ.get() > prevNum - 2:
                            return False
            
            prevNum, prevCnt = curNum, curCnt

        while not headsQ.empty():
            if headsQ.get() + 2 > prevNum:
                return False
        
        return True


if __name__ == "__main__":
    nums =  [1,2,3,3,4,4,5,5]
    S = Solution()
    S.isPossible2(nums)
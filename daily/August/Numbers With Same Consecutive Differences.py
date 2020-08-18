from typing import List

class Solution:
    def numsSameConsecDiff(self, length: int, diff: int) -> List[int]:
        res = []
        if length == 1:
            return [i for i in range(10)]

        for i in range(1, 10):
            self.dfs(i, diff, length - 1, res)

        res.sort()
        return res
    
    def dfs(self, num, diff, depth, addTo: List):
        if depth == 0:
            addTo.append(num)
            return
        
        nextNum = num % 10 + diff
        if nextNum < 10:
            self.dfs(num * 10 + nextNum, diff, depth - 1, addTo)

        if diff == 0:
            return

        nextNum = num % 10 - diff
        if nextNum >= 0:
            self.dfs(num * 10 + nextNum, diff, depth - 1, addTo)


if __name__ == "__main__":
    print(Solution().numsSameConsecDiff(3, 7))
    print(Solution().numsSameConsecDiff(2, 1))
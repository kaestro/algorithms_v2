from typing import List

class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        permut = [i for i in range(1,m+1)]
        res = []
        for query in queries:
            idx = permut.index(query)
            res.append(idx)
            permut.pop(idx)
            permut.insert(0, query)
        return res


if __name__ == "__main__":
    S = Solution()
    ans = S.processQueries([3,1,2,1], 5)
    print(ans)
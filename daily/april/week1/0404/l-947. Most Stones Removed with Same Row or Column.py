class Stone:
    def __init__(self, max_row):
        self.stones = list(range(2 * max_row))
    

    def findRoot(self, child:int) -> int:
        if self.stones[child] != child:
            self.stones[child] = self.findRoot(self.stones[child])
        return self.stones[child]
    

    def union(self, lhs, rhs):
        root1 = self.findRoot(lhs)
        root2 = self.findRoot(rhs)
        self.stones[root2] = root1



class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        nStones = len(stones)
        for x, i in enumerate(stones):
        for x, y in stones:
            res.union(x,y + 10000)
        
        return nStones - len({res.findRoot(x) for x, y in stones})
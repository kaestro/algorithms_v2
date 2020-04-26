import collections

class Solution:
    def __init__(self):
        self.points = set()
        self.rowToCol = collections.defaultdict(list)
        self.colToRow = collections.defaultdict(list)


    def removeStones(self, stones: List[List[int]]) -> int:
        num_islands = 0
        for x, y in stones:
            self.points.add((x,y))
            self.rowToCol[x].append(y)
            self.colToRow[y].append(x)
        
        for x, y in stones:
            if (x,y) in self.points:
                self.dfs(x, y)
                num_islands += 1
        
        return len(stones) - num_islands

    
    def dfs(self, row, col):
        self.points.discard((row,col))

        for rc in self.rowToCol[row]:
            if (row, rc) in self.points:
                self.dfs(row, rc)

        for cr in self.colToRow[col]:
            if (cr, col) in self.points:
                self.dfs(cr, col)
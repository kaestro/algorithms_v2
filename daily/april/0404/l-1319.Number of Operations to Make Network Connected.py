import collections
from typing import List


class UnionFind:
    def __init__(self, num_computers):
        self.parents = list(range(num_computers))


    def find(self, child):
        if self.parents[child] != child:
            self.parents[child] = self.find(self.parents[child])
        return self.parents[child]
    

    def union(self, lhs, rhs):
        lParent = self.find(lhs)
        rParent = self.find(rhs)
        self.parents[rParent] = lParent


class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        network = UnionFind(n)

        for x, y in connections:
            network.union(x,y)
        
        needed_lines = len({network.find(x) for x in range(n)}) - 1
        connected = collections.Counter(network.parents)
        used = sum(y - 1 for x, y in connected.items())
        if needed_lines <= len(connections) - used:
            return needed_lines
        else:
            return -1


if __name__ == "__main__":
    n = 4
    connections =  [[0,1],[0,2],[1,2]]
    S = Solution()

    S.makeConnected(n, connections)
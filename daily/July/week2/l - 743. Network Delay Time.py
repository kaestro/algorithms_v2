from typing import List

class Solution:
    MAX_DIST = 600_000

    def __init__(self):
        self.dists = []
        self.selected = []
        self.cntSelected = 0
        self.numNodes = 0
        self.start = 0


    def networkDelayTime(self, times: List[List[int]], numNodes: int, start: int) -> int:
        self.dists = [None] * (numNodes + 1)
        self.selected = [False] * (numNodes + 1)
        self.dists[start] = 0
        self.numNodes = numNodes
        self.cntSelected = 0

        ans = 0
        while True:
            selectedNode = self.selectMinNode()
            if selectedNode is None:
                ans = -1
                break
            else:
                self.expand(selectedNode, times)

                if self.cntSelected == numNodes:
                    ans = max(x for x in self.dists if x is not None)
                    break
        return ans
    

    def selectMinNode(self):
        minIdx, minDist = None, None
        for idx, dist in enumerate(self.dists[0:]):
            if self.selected[idx]:
                continue

            if (minDist is None and dist is not None):
                minIdx, minDist = idx, dist
            elif minDist is not None and dist is not None and dist < minDist:
                minIdx, minDist = idx, dist

        if minIdx is not None:
            self.selected[minIdx] = True
            self.cntSelected += 1

        return minIdx
    
    def expand(self, minNode, times):
        for time in times:
            src, tar, weight = time[:]
            if src != minNode:
                continue

            if self.dists[tar] is None or self.dists[tar] > self.dists[src] + weight:
                self.dists[tar] = self.dists[src] + weight


if __name__ == "__main__":
    times = [[2,1,1],[2,3,1],[3,4,1]]
    N = 4
    K = 2
    times = [[1,2,1],[2,1,3]]
    N = 2
    K = 2

    S = Solution()
    print(S.networkDelayTime(times, N, K))

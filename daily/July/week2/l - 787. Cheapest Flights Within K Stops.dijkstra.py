from typing import List
from collections import defaultdict
import heapq

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        graph = defaultdict(list)
        for u, v, w in flights:
            graph[u].append((w, v))

        shortestPaths = defaultdict(list)
        priorityQueue = [(0, K + 1, src)]
        while priorityQueue:
            cost, stops, city = heapq.heappop(priorityQueue)

            if city == dst:
                return cost
            
            if stops == 0:
                continue
            
            for price_i, city_i in graph[city]:
                heapq.heappush(priorityQueue, (cost + price_i, stops - 1, city_i))

        return -1


if __name__ == "__main__":
    S = Solution()
    n = 3
    edges = [[0,1,100],[1,2,100],[0,2,500]]
    src = 0
    dst = 2
    k = 0

    n = 5
    edges = [[4,1,1],[1,2,3],[0,3,2],[0,4,10],[3,1,1],[1,4,3]]
    src = 2
    dst = 1
    k = 1

    n = 4
    edges = [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
    src = 0
    dst = 3
    k = 1

    print(S.findCheapestPrice(n, edges, src, dst, k))
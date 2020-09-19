# https://leetcode.com/problems/network-delay-time/
# algorithm: Dijkstra's, graph
# date: 09.19.2020

from typing import List
from queue import PriorityQueue
from math import inf
from collections import defaultdict


class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        dists = [inf] * (N + 1)
        dists[K] = 0
        graph = [defaultdict(int) for _ in range(N + 1)]
        for src, dst, weight in times:
            graph[src][dst] = weight
        
        pq = PriorityQueue()
        pq.put((0, K))

        visited = set()
        while not pq.empty():
            minDist, node = pq.get()
            if node in visited:
                continue
            
            visited.add(node)

            for dst, weight in graph[node].items():
                nextDist = minDist + weight
                if dists[dst] == inf or dists[dst] > nextDist:
                    dists[dst] = nextDist
                    pq.put((nextDist, dst))


            if len(visited) == N:
                break

        return max(dists[1:]) if len(visited) == N else -1


if __name__ == "__main__":
    times = [[2,1,1],[2,3,1],[3,4,1]]
    N = 4
    K = 2
    solution = Solution()
    times = [[1,2,1]]
    N, K = 2, 2
    print(solution.networkDelayTime(times, N, K))
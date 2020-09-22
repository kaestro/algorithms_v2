# https://leetcode.com/problems/cheapest-flights-within-k-stops/
# algorithm: dijkstra's, graph
# date: 09.22.2020


from typing import List
from collections import defaultdict
from queue import PriorityQueue
from math import inf


class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], start: int, goal: int, K: int) -> int:
        graph = defaultdict(list)
        for src, dst, weight in flights:
            graph[src].append((dst, weight))

        
        pq = PriorityQueue()
        pq.put((0, start, K))

        while not pq.empty():

            dist, node, steps = pq.get()
            
            if node == goal:
                return dist
            
            if steps == -1:
                continue
            
            steps -= 1
            for dst, weight in graph[node]:
                pq.put((weight + dist, dst, steps))

        return -1


if __name__ == "__main__":
    n = 3
    edges = [[0,1,100],[1,2,100],[0,2,500]]
    src = 0
    dst = 2
    k = 1
    print(Solution().findCheapestPrice(n, edges, src, dst, k))
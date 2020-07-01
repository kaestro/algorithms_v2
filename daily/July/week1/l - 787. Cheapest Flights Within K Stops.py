from typing import List

maxPrice = 100 * 10000

class Solution:

    def findCheapestPrice(self, numCities: int, flights: List[List[int]], begin: int, end: int, maxStop: int) -> int:
        global maxPrice
        minCosts = [maxPrice] * numCities
        minCosts[begin] = 0

        for _ in range(maxStop + 1):
            nextMinCosts = minCosts[:]
            for flight in flights:
                src, dst, weight = flight[:]
                nextMinCosts[dst] = min(nextMinCosts[dst], minCosts[src] + weight)
            minCosts = nextMinCosts[:]
        
        return minCosts[end] if minCosts[end] != maxPrice else -1


if __name__ == "__main__":
    S = Solution()
    numCities, edges = 3,  [[0,1,100],[1,2,100],[0,2,500]]
    begin, end, maxStop = 0, 2, 1
    S.findCheapestPrice(numCities, edges, begin, end, maxStop)

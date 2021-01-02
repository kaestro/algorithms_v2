from typing import List

class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        # neighborcount, last color, total cost
        que = []
        houseCnt = len(houses)

        if houses[0] != 0:
            que.append([1, houses[0], 0])
        else:
            for i in range(n):
                que.append([1, i + 1, cost[0][i]])
        
        for i in range(1, m):
            house = houses[i]
            nextQue = []
            for job in que:
                if house != 0:
                    neighborhood, lastColor, totalCost = job[:]
                    if lastColor == house:
                        nextQue.append(job[:])
                    elif neighborhood != target:
                        nextQue.append([neighborhood + 1, house, totalCost])
                    continue

                for color in range(1, n+1):
                    neighborhood, lastColor, totalCost = job[:]
                    if color != lastColor:
                        if neighborhood == target:
                            continue
                        neighborhood += 1
                    totalCost += cost[i][color-1]
                    nextQue.append([neighborhood, color, totalCost])
            que = nextQue

        minCost = None
        for job in que:
            neighborhood, lastColor, totalCost = job
            if minCost is None or minCost > totalCost:
                minCost = totalCost
        
        return minCost if minCost is not None else -1

if __name__ == "__main__":
    houses = [0,0,0,0,0]
    #houses = [0,2,1,2,0]
    cost = [[1,10],[10,1],[10,1],[1,10],[5,1]]
    m = 5
    n = 2
    target = 3

    houses = [2, 3, 0]
    cost = [[5,2,3], [3,4,1], [1,2,1]]
    m = 3
    n = 3
    target = 3

    sol = Solution()
    print(sol.minCost(houses, cost, m, n, target))

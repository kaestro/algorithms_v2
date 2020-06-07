from typing import List


class Dp:

    def __init__(self, lastBlockColor:int, numNeighbors:int):
        self.lastBlockColor = lastBlockColor
        self.numNeighbors = numNeighbors
    

    def __hash__(self):
        return hash((self.lastBlockColor, self.numNeighbors))
    

    def __eq__(self, other):
        return (self.lastBlockColor, self.numNeighbors) == (other.lastBlockColor, other.numNeighbors)
    

    def __ne__(self, other):
        return not (self == other)


White = 0


class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], numHouse: int, numColor: int, targetNeighbor: int) -> int:
        dp, dp2 = {Dp(0,0): 0}, {}

        for idx, houseColor in enumerate(houses):
            for color in range(1, numColor + 1 if houseColor == White else [houseColor]):
                for key in dp:
                    nextNeighbor = key.numNeighbors + (dp2.lastBlockColor != color)

                    if nextNeighbor > targetNeighbor:
                        continue

                    dp2[key.lastBlockColor, nextNeighbor] = min(dp2.get((key.lastBlockColor, nextNeighbor), float('inf')), dp[color, key.numNeighbors] + (cost[idx][color - 1] if color != houseColor else 0) )
            dp, dp2 = dp2, {}
        return min([dp[color, numNeighbor] for color, numNeighbor in dp if numNeighbor == targetNeighbor] or [-1])
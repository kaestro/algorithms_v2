#Best time to buy and sell stock.

from typing import List

class Solution:
    def naive_maxProfit(self, prices: List[int]) -> int:
        ans = 0
        length = len(prices)
        for (i, val) in enumerate(prices):
            for j in range(i+1, length):
                ans = max(ans, prices[j] - val)
        
        return ans
    
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        if len(prices) == 0: return 0
        max_right = prices[-1]
        for i in range(len(prices)-1, -1, -1):
            if prices[i] > max_right:
                max_right = prices[i]
            else:
                diff = max_right - prices[i]
                ans = max(diff, ans)
        return ans
    
    # Use the maximum subsum array algorithm
    def subsum_maxProfit(self, prices: List[int]) -> int:
        ans = 0
        if len(prices) < 2: return 0
        diffs = []
        for i in range(len(prices)-1):
            diffs.append(prices[i+1] - prices[i])
        
        ans = max(ans, diffs[0])
        for i in range(1,len(diffs)):
            if diffs[i-1] > 0:
                diffs[i] += diffs[i-1]
            ans = max(ans, diffs[i])

        return ans
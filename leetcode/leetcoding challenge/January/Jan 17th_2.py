class Solution:
    def countVowelStrings(self, n: int) -> int:
        if n == 1:
            return 5

        dp = {(1, i):i for i in range(1, 6)}
        for k in range(2, n+1):
            for i in range(5, 0, -1):
                dp[k, i] = 0 
                for j in range(1, i+1):
                    dp[k, i] += dp[k-1, j]

        return dp[n, 5]


if __name__ == "__main__":
    n = int(input())
    sol = Solution()
    ans = sol.countVowelStrings(n)
    print(ans)

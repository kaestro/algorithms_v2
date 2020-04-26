class Solution:
    def climbStairs(self, n: int) -> int:
        cases = [0] * (n+1)
        cases[0], cases[1] = 1, 1
        for i in range(2,n):
            cases[i] = cases[i-1] + cases[i-2]
        return cases[n-1]


if __name__ == "__main__":
    S = Solution()
    print(S.climbStairs())
import random

class Solution(object):
    def isHappy(self, n):
        used = []
        while True:
            for num in used:
                if num == n:
                    return False
            used.append(n)
            n = self.helper(n)
            if n == 1: break
        return True

    def helper(self, n):
        ans = 0
        while n > 0:
            ans += (n % 10) ** 2
            n //= 10
        return ans


if __name__ == "__main__":
    random.seed(1)
    S = Solution()
    for _ in range(100):
        val = random.randint(0, 1000)
        print(str(val), str(S.isHappy(val)))
    
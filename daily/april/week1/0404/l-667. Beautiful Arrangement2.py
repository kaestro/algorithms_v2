from typing import List


class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        ans = []
        for i in range(1,k+2):
            if i % 2 == 1:
                ans.append((i+1) // 2)
            else:
                ans.append(k+2 - i//2)
        ans = ans + [i for i in range(k+2, n+1)]
        return ans


if __name__ == "__main__":
    S = Solution()
    print(S.constructArray(5,4))
    print(S.constructArray(5,1))

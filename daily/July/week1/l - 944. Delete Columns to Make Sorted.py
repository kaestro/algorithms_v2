from typing import List

class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        num = 0
        index = 0
        while True:
            prevChar = None
            for word in A:
                char = word[index]
                if prevChar is None or ord(prevChar) <= ord(char):
                    prevChar = char
                else:
                    num += 1
                    break
            index += 1
            if index == len(A[0]):
                break
        return num


if __name__ == "__main__":
    A = ["a","b"]
    S = Solution()
    S.minDeletionSize(A)
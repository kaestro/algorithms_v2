from itertools import permutations

class Solution:
    def __init__(self):
        self.vowels = ['a','e','i','o','u']

    def countVowelStrings(self, n: int) -> int:
        ans = []
        self.backTrack("", n, ans)
        return len(ans)
    

    def backTrack(self, str, n, lines:list):
        if len(str) == n:
            lines.append(str)
            return


        for vowel in self.vowels:
            if str == "" or ord(vowel) >= ord(str[-1]):
                self.backTrack(str + vowel, n, lines)


if __name__ == "__main__":
    n = int(input())
    sol = Solution()
    ans = sol.countVowelStrings(n)
    print(ans)
#count the number of Palindromic substrings

class Solution:
    def countSubstrings(self, s: str) -> int:
        slen = len(s)
        if slen == 0: return 0
        ans = slen
        for i in range(slen-1):
            j = 1
            # find odd palindromes
            while i - j >= 0 and i + j < slen:
                if s[i - j] == s[i + j]:
                    ans += 1
                    j += 1
                else:
                    break
            
            # find even palindromes
            if s[i] == s[i+1]:
                j = 0
                while i - j >= 0 and i+1 + j < slen:
                    if s[i - j] == s[i+1 + j]:
                        ans += 1
                        j += 1
                    else:
                        break
        return ans


class Dynamyc_Solution:
    def countSubstrings(self, s: str) -> int:
        slen = len(s)
        ans = slen
        if slen == 0: return 0

        is_palindrome = [[False for x in range(slen)] for y in range(slen)]
        for i in range(slen):
            is_palindrome[i][i] = True
        
        for i in range(slen):
            for j in range(i-1, -1, -1):
                if j == i - 1:
                    is_palindrome[i][j] = (s[i] == s[j])
                else:
                    is_palindrome[i][j] = (is_palindrome[i-1][j+1] and s[i] == s[j])
                if is_palindrome[i][j]: ans += 1
        
        return ans
    
    def betterCode(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]

        res = 0
        # loop must start from end for we will look for i+1
        for i in range(n-1, -1, -1):
            for j in range(i, n):
                dp[i][j] = (s[i] == s[j]) and (j - i + 1 < 3 or dp[i+1][j-1])
                res += dp[i][j]
        return res





class Brute_Solution:
    def countSubstrings(self, s: str) -> int:
        length = len(s)
        if length == 0: return 0

        ans = length

        for i in range(length):
            for j in range(i+1, length):
                if self.isPalindrome(s[i:j+1]):
                    ans += 1
        return ans
        
    def isPalindrome(self, s: str) -> bool:
        length = len(s)
        for i in range(length):
            if s[i] != s[length - i - 1]:
                return False
        return True

if __name__ == "__main__":
    s = "abc"
    Dynamyc_Solution().betterCode(s)
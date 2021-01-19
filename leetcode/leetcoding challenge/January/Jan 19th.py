class Solution:
    def longestPalindrome(self, s: str) -> str:
        dp = {}
        slen = len(s)
        maxlen, maxstr = 1, s[0]

        for i in range(slen):
            dp[i,i] = True
            if i != slen-1 and s[i] == s[i+1]:
                dp[i, i+1] = True
                maxlen = 2
                maxstr = s[i:i+2]
            else:
                dp[i, i+1] = False
                break
        
        for i in range(slen):
            right = i+1
            left  = i-1
            while left >= 0 and right < slen:
                if s[left] == s[right] and dp[left+1, right-1]:
                    dp[left, right] = True
                    if right - left + 1 > maxlen:
                        maxlen = right - left + 1
                        maxstr = s[left:right+1]
                else:
                    dp[left,right] = False
                    break
                left -= 1
                right += 1
            
            left = i-1
            right = i+2
            while left >= 0 and right < slen:
                if s[left] == s[right] and dp[left+1, right-1]:
                    dp[left, right] = True
                    if right - left + 1 > maxlen:
                        maxlen = right - left + 1
                        maxstr = s[left:right+1]
                else:
                    dp[left,right] = False
                left -= 1
                right += 1
 
        return maxstr


if __name__ == "__main__":
    sol = Solution()
    print(sol.longestPalindrome(input()))
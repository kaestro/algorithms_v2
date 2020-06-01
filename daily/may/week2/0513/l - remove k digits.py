class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if k >= len(num): return "0"

        ans = [digit for digit in num]
        while k > 0:
            next_k = k
            i = 0
            while i < len(ans) - 1:
                if int(ans[i]) > int(ans[i + 1]):
                    ans.pop(i)
                    next_k -= 1
                    if next_k == 0:
                        break

                    if i != 0:
                        i -= 1
                else:
                    i += 1
            
            if k == next_k: break

            k = next_k
        
        if k > 0:
            return str(int(''.join(ans[0:-k])))
        return str(int(''.join(ans)))


if __name__ == "__main__":
    s = Solution()
    num = "1432219"
    k = 3
    print(s.removeKdigits(num, k))
    num, k = "0", 0
    print(s.removeKdigits(num, k))
    num, k = "10200", 1
    print(s.removeKdigits(num, k))
    num, k = "10", 2
    print(s.removeKdigits(num, k))
    num, k = "10", 1
    print(s.removeKdigits(num, k))
    num, k = "1234567890", 9
    print(s.removeKdigits(num, k))
    num, k = "112", 1
    print(s.removeKdigits(num, k))

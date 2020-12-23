class Solution:
    def reformatNumber(self, number: str) -> str:
        number = number.replace(' ', '')
        number = number.replace('-', '')

        ans = []
        for idx, num in enumerate(number):
            ans.append(num)
            if idx % 3 == 2:
                ans.append('-')
        if ans[-1] == '-':
            ans.pop()
        
        if len(number) > 3 and len(number) % 3 == 1:
            ans[-3], ans[-2] = ans[-2], ans[-3]


        return ''.join(ans)


if __name__ == "__main__":
    sol = Solution()
    number = "1-23-45 6"
    number = "123 4-567"
    number = "12345678"
    print(sol.reformatNumber(number))
class Solution:
    def findComplement(self, num: int) -> int:
        num = bin(num)[2:]
        num = ''.join(['0' if i == '1' else '1' for i in num])
        return int(num, 2)


if __name__ == "__main__":
    s = Solution()
    s.findComplement(5)
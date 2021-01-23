from collections import Counter

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False
        
        dict1 = Counter([ch for ch in word1])
        dict2 = Counter([ch for ch in word2])

        keys1 = list(dict1.keys())
        keys2 = list(dict2.keys())

        keys1.sort()
        keys2.sort()

        values1 = list(dict1.values())
        values2 = list(dict2.values())

        values1.sort()
        values2.sort()

        return keys1 == keys2 and values1 == values2
    

if __name__ == "__main__":
    word1, word2 = "abc", "bca"
    sol = Solution()
    print(sol.closeStrings(word1, word2))
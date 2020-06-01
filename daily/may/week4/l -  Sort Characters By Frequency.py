from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        char_cnt = Counter(s)
        ans_list = []
        for char, cnt in sorted(char_cnt.items(), key = lambda x : x[1], reverse = True):
            ans_list.append(char * cnt)
        return ''.join(ans_list)


if __name__ == "__main__":
    s = Solution()
    string = "tree"
    print(s.frequencySort(string))

from typing import List

class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        len_words = len(words)
        res = []
        for i in range(len_words):
            for j in range(len_words):
                if j == i: continue
                if words[j].find(words[i]) != -1:
                    res.append(words[i])
                    break
        return res

from typing import List


class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        outgoing = set()
        ans_candidates = []
        for path in paths:
            starting, destination = path[:]
            if destination not in outgoing:
                ans_candidates.append(destination)
            if starting in ans_candidates:
                ans_candidates.remove(starting)
            outgoing.add(starting)
        return ans_candidates[0]


if __name__ == "__main__":
    paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
    paths = [["B","C"],["D","B"],["C","A"]]
    s = Solution()
    print(s.destCity(paths))

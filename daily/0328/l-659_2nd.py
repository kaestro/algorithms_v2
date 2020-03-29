import collections
import itertools

class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        prev, prev_count = None, 0
        starts = collections.deque()
        for t, grp in itertools.groupby(nums):
            count = len(list(grp))
            if prev is not None and t != prev + 1:
                for _ in range(prev_count):
                    if prev < starts.popleft() + 2:
                        return False
                prev, prev_count = None, 0
            
            if prev is None or t == prev + 1:
                if count > prev_count:
                    for _ in range(count - prev_count):
                        starts.append(t)
                elif count < prev_count:
                    for _ in range(prev_count - count):
                        if t - 1 < starts.popleft() + 2:
                            return False
            
            prev, prev_count = t, count

        return all(nums[-1] >= x + 2 for x in starts)
# https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
# date: 09.21.2020



from typing import List


class Solution:

    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()
        date = -1
        numEvents = 0
        for startDay, endDay in events:
            if date < startDay:
                date = startDay
                numEvents += 1
            elif date < endDay:
                date += 1
                numEvents += 1
        return numEvents


if __name__ == "__main__":
    eventsList = [
            # [[1,2],[2,3],[3,4]],
            # [[1,4],[4,4],[2,2],[3,4],[1,1]],
            [[1,2],[1,2],[3,3],[1,5],[1,5]]
        ]
    for events in eventsList:
        print(Solution().maxEvents(events))
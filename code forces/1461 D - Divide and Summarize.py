import bisect

if __name__ == "__main__":
    t = int(input())

    while t > 0:
        t -= 1
        n, q = map(int, input().split())
        nums = list(map(int, input().split()))
        q = list(map(int, input().split()))
        sums = set()

        nums.sort()
        lists = [nums]
        while lists:
            nextLists = []

            for lst in lists:
                sums.add(sum(lst))
                if len(lst) == 1:
                    continue

                mid = (lst[0] + lst[-1]) // 2
                idx = bisect.bisect_left(lst, mid)
                left = lst[:idx]
                right = lst[idx:]

                if len(left) > 0:
                    nextLists.append(left)
                if len(right) > 0:
                    nextLists.append(right)

            lists = nextLists
        
        for num in q:
            if q in sums:
                print("YES")
            else:
                print("NO")
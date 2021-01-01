T = int(input())
cnt = 0
while cnt < T:
    cnt += 1
    ans = 0

    N, Budget = map(int, input().split())
    houses = list(map(int, input().split()))

    houses.sort()

    sum = 0
    for house in houses:
        sum += house
        if sum > Budget:
            break
        ans += 1

    print("Case #{}: {}".format(cnt, ans))

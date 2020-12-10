t = int(input())
while t > 0:
    t -=1
    m, n = map(int, input().split())
    print("{} {}".format(m-1, n))
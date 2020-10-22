# https://codeforces.com/problemset/problem/4/C
# algorithm: hashing
# date: 10.23.2020
# purpose: first attempt

from collections import defaultdict

if __name__ == "__main__":
    cnt = int(input())
    name_cnt = defaultdict(int)

    for _ in range(cnt):
        name = input()

        if name not in name_cnt:
            name_cnt[name] = 1
            print("OK")
        else:
            print(name + str(name_cnt[name]))
            name_cnt[name] += 1
# https://codeforces.com/problemset/problem/189/A
# date: 10.23.2020
# purpose: first attempt

if __name__ == "__main__":
    nums = list(map(int, input().split()))
    n, a, b, c = nums[:]
    max_cnt = [0] * (n + 1)

    for num in nums[1:]:
        max_cnt[num] = 1

    for idx in range(n + 1):
        for num in nums[1:]:
            if idx - num == 0:
                max_cnt[idx] = max(max_cnt[idx], 1)
            elif idx - num > 0:
                max_cnt[idx] = max(max_cnt[idx], max_cnt[idx - num] + 1)

    print(max_cnt[n])
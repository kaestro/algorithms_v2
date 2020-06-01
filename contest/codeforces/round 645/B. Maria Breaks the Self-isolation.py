from collections import Counter

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        nums = list(map(int, input().split()))
        num_cnt = Counter(nums)
        ans_cnt, ans_key, cur_cnt = 1, 0, 0
        for key, cnt in num_cnt.items():
            cur_cnt += cnt
            if cur_cnt >= key:
                ans_cnt = cur_cnt
        
        print(ans_cnt + 1)
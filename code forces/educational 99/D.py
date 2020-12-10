if __name__ == "__main__":
    t = int(input())

    while t > 0:
        t -= 1
        n, x = map(int, input().split())
        nums = list(map(int, input().split()))

        if nums == list(sorted(nums)):
            print(0)
        else:
            cnt = 0
            for idx, num in enumerate(nums):
                if num > x:
                    if nums[idx:] == list(sorted(nums[idx:])):
                        break
                    else:
                        nums[idx], x = x, num
                        cnt += 1
            if nums == list(sorted(nums)):
                print(cnt)
            else:
                print(-1)
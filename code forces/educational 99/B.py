if __name__ == "__main__":
    t = int(input())

    while t > 0:
        t -= 1
        n = int(input())
        sum = 0
        step = 0
        while sum < n:
            step += 1
            sum += step
        if sum == n + 1:
            ans = step + 1
        else:
            ans = step

        #print("ans: {}".format(ans))
        print(ans)
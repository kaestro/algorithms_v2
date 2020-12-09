if __name__ == "__main__":
    t = int(input())
    while t > 0:
        t -= 1
        n, m = map(int, input().split())
        col = set(map(int, input().split()))
        row = set(map(int, input().split()))
        print(len(col & row))
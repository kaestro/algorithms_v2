from math import log10
from math import ceil
from math import floor

if __name__ == "__main__":
    t = int(input())

    while t > 0:
        t -= 1
        n = int(input())
        cnt = 0
        while n > 0:
            n //= 10
            cnt += 1
        print(cnt)
from collections import Counter

def Solution():
    line = input()
    ans = []
    for idx, ch in enumerate(line):
        if ch != ')':
            ans.append(ch)
        else:
            temp = []
            while ans[-1] != '(':
                temp.append(ans.pop())
            ans.pop()
            times = int(ans.pop())
            for _ in range(times):
                ans += temp[::-1]
    
    moveCnt = Counter(ans)
    right = moveCnt.get('E', 0) - moveCnt.get('W', 0)
    up = moveCnt.get('S', 0) - moveCnt.get('N', 0)
    dig1 = (1 + right) % (10 ** 9)
    dig2 = (1 + up) % (10 ** 9)
    return (dig1 if dig1 != 0 else 10 ** 9, dig2 if dig2 != 0 else 10 ** 9)


if __name__ == "__main__":
    t = int(input())

    for i in range(1, t+1):
        s = Solution()
        print("Case #{}: {} {}".format(i, s[0], s[1]))


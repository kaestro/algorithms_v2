if __name__ == "__main__":
    t = int(input())
    while t > 0:
        t -= 1
        n = int(input())
        string = input()[::-1]
        i = 0
        while i < n:
            if string[i] == ')':
                i += 1
            else:
                break
        if i > n / 2:
            print('Yes')
        else:
            print('No')
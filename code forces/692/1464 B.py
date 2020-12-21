def nextFairNum(num):
    fairNum, isFair = num - 1, False

    while not isFair:
        fairNum += 1
        copyNum = fairNum
        while copyNum > 0:
            divNum = copyNum % 10
            if divNum == 0 or fairNum % divNum == 0:
                copyNum //= 10
            else:
                break

        if copyNum == 0:
            isFair = True


    return fairNum



if __name__ == "__main__":
    t = int(input())
    while t > 0:
        t -= 1
        num = int(input())
        print(nextFairNum(num))
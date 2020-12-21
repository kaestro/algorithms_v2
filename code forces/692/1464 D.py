if __name__ == "__main__":
    one, zero, quest = '1', '0', '?'
    numStr = input()[::-1]
    oneZero, zeroOne = map(int, input().split())

    length = len(numStr)
    oneCnt, zeroCnt, questCnt = 0, 0, 0
    sum = 0
    questOneZeroSum, questZeroOneSum = 0, 0
    for digit in numStr:
        if digit == one:
            sum += zeroCnt * oneZero
            questOneZeroSum += 

            oneCnt += 1
        elif digit == zero:
            sum += zeroOne

            zeroCnt += 1
        else:

            questCnt += 1


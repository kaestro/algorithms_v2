# https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo
# algorithm: queue
# date: 10.01.2020
# purpose: review

from queue import deque
import sys


sys.stdin = open("sample_input.txt", "r")

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N, K = map(int, input().split())
    numString = input()
    numQue = deque(ch for ch in numString)
    numStrLen = len(numQue)
    numLen = numStrLen // 4
    numSet = set()

    for i in range(numLen):
        numQue.rotate(1)
        numList = list(numQue)
        for j in range(4):
            startIdx = j * numLen
            endIdx = startIdx + numLen
            numStr = numList[startIdx:endIdx]
            num = int(''.join(numStr), 16)
            numSet.add(num)

    numList = list(numSet)
    numList.sort(reverse=True)
    print("#{} {}".format(str(test_case), str(numList[K - 1])))


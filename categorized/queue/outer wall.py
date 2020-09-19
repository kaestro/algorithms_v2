# https://programmers.co.kr/learn/courses/30/lessons/60062?language=python3
from itertools import permutations


def solution(n, weak, dist):
    answer = len(dist) + 1
    weakCnt = len(weak)
    orders = permutations(dist, len(dist))
    for order in orders:
        for posIdx in range(0, weakCnt):
            personCnt, fixedCnt = 0, 0
            for person in order:
                startPos = weak[posIdx]
                personCnt += 1
                fixedCnt += 1
                endPos = (startPos + person) % n
                while fixedCnt < weakCnt:
                    posIdx = (posIdx + 1) % weakCnt
                    nextPos = weak[posIdx]

                    if startPos > endPos and nextPos > endPos and nextPos < startPos:
                        break
                    elif startPos < endPos and (nextPos > endPos or nextPos < startPos):
                        break
                    else:
                        fixedCnt += 1


                if fixedCnt == weakCnt:
                    answer = min(answer, personCnt)
                    break

    return answer if answer != len(dist) + 1 else -1


if __name__ == "__main__":
    n = 12
    weak = [1, 5, 6, 10]
    dist = [1,2,3,4]
    print(solution(n, weak, dist))
    
    n = 12
    weak = [1, 3, 4, 9, 10]	
    dist = [3, 5, 7]	
    print(solution(n, weak, dist))
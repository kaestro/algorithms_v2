# https://programmers.co.kr/learn/courses/30/lessons/72411

from collections import defaultdict
from itertools import combinations


def solution(orders, course):
    answer = []
    cnts = {}
    for cnt in course:
        cnts[cnt] = defaultdict(int)
    
    for i in range(len(orders)):
        order = orders[i]
        orders[i] = ''.join(sorted(order))
    
    for order in orders:
        for cnt in course:
            for comb in combinations(order, cnt):
                cnts[cnt][comb] += 1

    for cnt in course:
        maxCnt = None
        for comb, num in sorted(cnts[cnt].items(), key=lambda x: x[1], reverse=True):
            if maxCnt == None:
                maxCnt = num
                if maxCnt == 1:
                    break
                answer.append(''.join(list(comb)))
            elif maxCnt == num:
                answer.append(''.join(list(comb)))
            else:
                break


    answer.sort()
    return answer


if __name__ == '__main__':
    orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
    course = [2,3,4]

    orders = 	["XYZ", "XWY", "WXA"]
    course = [2, 3, 4]

    solution(orders, course)
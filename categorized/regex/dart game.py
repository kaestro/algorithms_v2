# https://programmers.co.kr/learn/courses/30/lessons/17682

import re


# pattern: 1S2D*3T	
def solution(dartResult):
    answer = 0
    pattern = "(\d+)([A-Z])+(\*?\#?)"
    scores = re.findall(pattern, dartResult)
    stack = [score for score in scores[::-1]]

    isDouble = False
    for num, bonus, option in stack:
        num = int(num)
        if bonus == "D":
            num *= num
        elif bonus == "T":
            num **= 3
        
        if option == "#":
            num *= -1
        
        if isDouble:
            num *= 2
        
        if option == "*":
            isDouble = True
            num *= 2
        else:
            isDouble = False
        
        answer += num

    return answer


if __name__ == "__main__":
    print(solution("1S2D*3T"))
from itertools import permutations

def solution(expression):
    answer = 0
    operators, numChr = ['+', '-', '*'], [chr(i) for i in range(ord('0'), ord('9') + 1)]
    numStack, operStack = [], []

    number = None
    for ch in expression:
        if ch in numChr:
            if number is None:
                number = ch
            else:
                number += ch
        else:
            numStack.append(int(number))
            number = None
            operStack.append(ch)
    numStack.append(int(number))


    for order in permutations(operators, 3):
        tempNumStack, tempOperStack = numStack[:], operStack[:]
        for oper in order:
            operCount = tempOperStack.count(oper)
            while operCount > 0:
                idx = tempOperStack.index(oper)
                tempOperStack.pop(idx)
                operCount -= 1
                if oper == "+":
                    tempNumStack[idx] += tempNumStack.pop(idx + 1)
                elif oper == "*":
                    tempNumStack[idx] *= tempNumStack.pop(idx + 1)
                else:
                    tempNumStack[idx] -= tempNumStack.pop(idx + 1)
        answer = max(answer, abs(tempNumStack[0]))

    return answer


if __name__ == "__main__":
    expression = "100-200*300-500+20"	
    print(solution(expression))
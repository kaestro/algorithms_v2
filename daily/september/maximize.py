from itertools import permutations

def solution(expression):
    answer = 0
    operators = ['+', '-', '*']
    for order in permutations(operators, 3):
        stack = []
        for oper in order:
            number = None
            for ch in expression:
                if ch in [chr(i) for i in range(ord('0'), ord('9') + 1)]:
                    if number is None:
                        number = ch
                    else:
                        number += ch
                elif ch == oper:
                    number = int(number)
                    top = stack.pop()
                    if oper == "+":
                        stack.append(top + number)
                    elif oper == "-":
                        stack.append(top - number)
                    else:
                        stack.append(top * number)
                    number = None
                else:
                    stack.append(int(number))
                    stack.append(ch)
                    number = None
        answer = max(answer, abs(stack[0]))

    return answer


if __name__ == "__main__":
    expression = "100-200*300-500+20"	
    print(solution(expression))
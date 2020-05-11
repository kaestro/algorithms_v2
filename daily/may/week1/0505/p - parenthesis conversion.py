# 괄호변환
def solution(string):
    if len(string) == 0: return string

    answer = ''
    left, right = '', ''
    left += string[0]
    cnt = -1 if left == '(' else 1
    isCorrect = (cnt == -1)
    for i in range(1, len(string)):
        cnt += (1 - 2 * (string[i] == '('))
        left += string[i]
        if cnt == 0:
            right = string[i+1:]
            break

    right = solution(right)
    if isCorrect:
        answer = left + right
    else:
        answer += '('
        answer += right
        answer += ')'
        left_converted = ''.join(['(' if ch == ')' else ')' for ch in left[1:-1]])
        answer += left_converted

    return answer


if __name__ == "__main__":
    p = "(()())()"
    print(solution(p))
    p = ")("
    print(solution(p))
    p = "()))((()"
    print(solution(p))
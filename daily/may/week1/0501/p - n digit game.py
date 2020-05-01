def solution(n, t, m, p):
    answer = ''
    full_string = '0'
    num, temp = 1, 1
    while len(full_string) < m * t:
        num = temp
        append_string = ""
        while num > 0:
            append_string += hex(num % n)[2:]
            num //= n
        full_string += append_string[::-1]
        temp += 1

    for i in range(p - 1, len(full_string), m):
        answer += full_string[i]

    return answer[0:t]

if __name__ == "__main__":
    print(solution(2, 4, 2, 1))
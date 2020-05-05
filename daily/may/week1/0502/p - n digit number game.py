def solution(n, t, m, p):
    answer = ''
    full_str = '0'
    temp, num = 1, 1
    while len(full_str) < m * t:
        num = temp
        apend_str = ''
        while num > 0:
            apend_str += hex(num % n)[2:].upper()
            num //= n
        full_str += apend_str[::-1]
        temp += 1
    
    for i in range(p - 1, m * t, m):
        answer += full_str[i]

    return answer[0:t]

if __name__ == "__main__":
    print(solution(2,4,2,1))
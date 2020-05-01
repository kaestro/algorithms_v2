def solution(msg:str)->[]:
    answer = []
    i = 0
    dic = {'A': 1, 'B':2, 'C':3, 'D':4, 'E': 5, 'F' : 6, 'G' : 7, 'H' : 8,
        'I' : 9, 'J' : 10, 'K' : 11, 'L': 12, 'M': 13, 'N' : 14, 'O' : 15,
        'P' : 16, 'Q' : 17, 'R' : 18, 'S' : 19, 'T' : 20, 'U' : 21, 'V' : 22,
        'W' : 23, 'X' : 24, 'Y' : 25, 'Z' : 26}
    len_msg = len(msg)
    next_int = 27
    while i < len_msg:
        j = i + 1
        while (j <= len_msg and msg[i:j] in dic): j += 1
        answer.append(dic[msg[i:j-1]])
        dic[msg[i:j]] = next_int
        next_int += 1
        i = j - 1
    return answer

if __name__ == "__main__":
    msg = 'KAKAO'
    print(solution(msg))
    msg = 'TOBEORNOTTOBEORTOBEORNOT'
    print(solution(msg))
    msg = 'ABABABABABABABAB'
    print(solution(msg))
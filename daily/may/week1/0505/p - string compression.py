# 문자열 압축
def solution(string:str)->int:
    answer = len(string)
    str_len = len(string)
    for sub_len in range(1, str_len // 2 + 1):
        compressed = []
        for idx in range(0, str_len, sub_len):
            if idx == 0:
                compressed.append([1, string[idx : idx + sub_len]])
            else:
                prev = compressed[-1]
                if prev[1] == string[idx : idx + sub_len]:
                    prev[0] += 1
                else:
                    compressed.append([1, string[idx : idx + sub_len]])
        
        cur_len = 0
        for cnt, val in compressed:
            cur_len += len(val)
            if cnt != 1: cur_len += len(str(cnt))
        
        answer = min(answer, cur_len)

    return answer


if __name__ == "__main__":
    print(solution("aabbaccc"))
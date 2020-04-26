def solution(s: str):
    answer = ''
    nums = list(map(int, s.split()))
    answer += str(min(nums))
    answer += " "
    answer += str(max(nums))
    return answer

if __name__ == "__main__":
    print(solution("1 2 3 4"))
def solution(s: str) -> list:
    answer = []
    new_str = s[1:-1].replace('},', '} ')
    new_list = new_str.split()
    new_list.sort(key=len)
    for nums in new_list:
        nums = nums [1:-1]
        temp = map(int, nums.split(','))
        for num in temp:
            if num not in answer:
                answer.append(num)
    return answer

if __name__ == "__main__":
    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}")
from collections import Counter

def solution(str1, str2):
    answer = 0
    str1, str2 = str1.lower(), str2.lower()
    left, right = [], []

    for i in range(len(str1) - 1):
        if str1[i:i+2].isalpha():
            left.append(str1[i:i+2])
    
    for i in range(len(str2) - 1):
        if str2[i:i+2].isalpha():
            right.append(str2[i:i+2])
    
    left, right = Counter(left), Counter(right)

    intersection = 0
    union = 0
    for key, val in left.items():
        union += val
    for key, val in right.items():
        union += val
    
    for key, val in left.items():
        if key in right:
            intersection += min(val, right[key])

    if union == 0:
        answer = 65536
    else:
        union -= intersection
        answer = int(intersection / union * 65536)

    return answer

if __name__ == "__main__":
    str1, str2 = "FRANCE", "french"
    print(solution(str1, str2))
    str1, str2 = "handshake", "shake hands"
    print(solution(str1, str2))
    str1, str2 = "aa1+aa2", "AAAA12"
    print(solution(str1, str2))
    str1, str2 = "E=M*C^2", "e=m*c^2"
    print(solution(str1, str2))


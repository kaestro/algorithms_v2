from collections import Counter

def solution(str1, str2):
    constant = 65536
    answer = 0

    str1, str2 = str1.lower(), str2.lower()
    left, right = [], []
    union = 0
    for i in range(len(str1) - 1):
        element = str1[i:i+2]
        if (element.isalpha()):
            left.append(element)

    union += len(left)
    left = Counter(left)
    
    for i in range(len(str2) - 1):
        element = str2[i:i+2]
        if (element.isalpha()):
            right.append(element)
    union += len(right)
    right = Counter(right)

    intersection = 0
    for key, val in left.items():
        if key in right.keys():
            intersection += min(val, right[key])
    
    union -= intersection
    if union == 0:
        answer = constant
    else:
        answer =  int(constant * intersection / union)

    return answer
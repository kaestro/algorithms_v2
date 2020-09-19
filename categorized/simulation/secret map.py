# https://programmers.co.kr/learn/courses/30/lessons/17681

def solution(n, arr1, arr2):
    arr1 = [bin(num)[2:].zfill(n) for num in arr1]
    arr2 = [bin(num)[2:].zfill(n) for num in arr2]
    orArr = []
    for i in range(n):
        num1 = arr1[i]
        num2 = arr2[i]
        line = ""
        for j in range(n):
            if num1[j] == '0' and num2[j] == '0':
                line += " "
            else:
                line += "#"
        orArr.append(line)
    return orArr
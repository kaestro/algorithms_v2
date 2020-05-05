def solution(n, arr1, arr2):
    answer = []
    arr1 = [bin(num)[2:].zfill(n) for num in arr1]
    arr2 = [bin(num)[2:].zfill(n) for num in arr2]

    for i in range(n):
        answer.append("")
        for j in range(n):
            if arr1[i][j] == '1' or arr2[i][j] == '1':
                answer[i] += '#'
            else:
                answer[i] += ' '


    return answer


if __name__ == "__main__":
    n = 5
    arr1 = [9, 20, 28, 18, 11]
    arr2 = [30, 1, 21, 17, 28]
    solution(n, arr1, arr2)
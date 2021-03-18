def solution(arr):
    answer = [0, 0]
    helper(arr, answer)
    return answer


def helper(arr, answer):
    if len(arr) == 1:
        answer[arr[0][0]] += 1
        return
    
    num = arr[0][0]
    isSame = True
    for row in arr:
        for block in row:
            if block != num:
                isSame = False
                break
        if not isSame:
            break
    
    if isSame:
        answer[num] += 1
    else:
        halfLen = len(arr) // 2
        arrs = []
        arrs.append([row[:halfLen] for row in arr[:halfLen]])
        arrs.append([row[:halfLen] for row in arr[halfLen:]])
        arrs.append([row[halfLen:] for row in arr[:halfLen]])
        arrs.append([row[halfLen:] for row in arr[halfLen:]])
        for ar in arrs:
            helper(ar, answer)

if __name__ == '__main__':
    arr = [[1,1,0,0],[1,0,0,0],[1,0,0,1],[1,1,1,1]]
    arr = [[1,1,1,1,1,1,1,1],[0,1,1,1,1,1,1,1],[0,0,0,0,1,1,1,1],[0,1,0,0,1,1,1,1],[0,0,0,0,0,0,1,1],[0,0,0,0,0,0,0,1],[0,0,0,0,1,0,0,1],[0,0,0,0,1,1,1,1]]
    print(solution(arr))
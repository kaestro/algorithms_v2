# https://www.geeksforgeeks.org/minimum-swaps-to-make-two-array-identical/

def solution(arrA, arrB):

    mp = {}
    for i in range(len(arrB)):
        mp[arrB[i]] = i
    
    for i in range(len(arrA)):
        arrB[i] = mp[arrA[i]]

    res = helper(arrB)
    return res


def helper(arr):

    visited = {k: False for k in range(len(arr))}
    arrPos = [*(enumerate(arr))]
    arrPos.sort(key = lambda it : it[1])

    res = 0
    for i in range(len(arr)):

        if visited[i] or arrPos[i][0] == i:
            continue

        cycle_size = 0
        j = i

        while not visited[j]:
            visited[j] = True
            j = arrPos[j][0]
            cycle_size += 1

        res += (cycle_size - 1)

    return res




if __name__ == "__main__":
    arrA = [3, 6, 4, 8]
    arrB = [4, 6, 8, 3]
    
    solution(arrA, arrB)
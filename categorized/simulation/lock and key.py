# https://programmers.co.kr/learn/courses/30/lessons/60059?language=python3
from copy import deepcopy

def solution(key, lock):
    lockLen, keyLen = len(lock), len(key)
    keySpot = [0] * (keyLen - 1)
    emptyLine = [0] * (lockLen + 2 * (keyLen - 1))
    board = []
    for _ in range(keyLen - 1):
        board.append(emptyLine[:])

    for line in lock:
        newLine = keySpot[:]
        newLine.extend(line)
        newLine.extend(keySpot)
        board.append(newLine)
    
    for _ in range(keyLen - 1):
        board.append(emptyLine[:])


    for row in range(0, lockLen + keyLen - 1):
        for col in range(0, lockLen + keyLen - 1):
            for _ in range(4):
                copyBoard = deepcopy(board)
                flag = True
                for keyRow in range(0, keyLen):
                    if not flag:
                        break
                    for keyCol in range(0, keyLen):
                        nextRow = row + keyRow
                        nextCol = col + keyCol
                        copyBoard[nextRow][nextCol] += key[keyRow][keyCol]

                        boardValue = copyBoard[nextRow][nextCol]
                        if boardValue == 2:
                            flag = False
                            break

                        if nextRow >= keyLen - 1 and nextRow < keyLen - 1 + lockLen:
                            if nextCol >= keyLen - 1 and nextCol < keyLen - 1 + lockLen:
                                if boardValue == 0:
                                    flag = False
                                    break

                if flag == True:
                    secondFlag = True
                    for checkRow in range(keyLen - 1, keyLen - 1 + lockLen):
                        if not secondFlag:
                            break
                        for checkCol in range(keyLen - 1, keyLen - 1 + lockLen):
                            if copyBoard[checkRow][checkCol] == 0:
                                secondFlag = False
                                break
                    if secondFlag:
                        return True

                key = rotateKey(key)

    return False


### Be Cautious
# In python, you must "Return" the value you changed
# If you're changing the value by reassigning it.
# https://robertheaton.com/2014/02/09/pythons-pass-by-object-reference-as-explained-by-philip-k-dick/
def rotateKey(key):
    key = list(map(list, zip(*key[::-1])))
    return key


if __name__ == "__main__":
    key = [[0, 0, 0], [1, 0, 0], [0, 1, 1]]	
    lock = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]	
    print(solution (key, lock))
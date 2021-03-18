def solution(maps):
    rowSize, colSize = len(maps), len(maps[0])
    dr, dc = [-1, 0, 1, 0], [0, 1, 0, -1]
    visited = [[False for _ in range(colSize)] for _ in range(rowSize)]
    q = [(1, (0, 0))]
    while q:
        cnt, pos = q.pop(0)
        if pos == (rowSize - 1, colSize - 1):
            return cnt
        
        for i in range(4):
            nextPos = (pos[0] + dr[i], pos[1] + dc[i])
            if isInMap(nextPos, rowSize, colSize) and isEmpty(maps, nextPos) and not visited[nextPos[0]][nextPos[1]]:
                visited[nextPos[0]][nextPos[1]] = True
                q.append((cnt+1, nextPos))

    return -1


def isInMap(pos, rowSize, colSize):
    return pos[0] < rowSize and pos[0] >= 0 and pos[1] >= 0 and pos[1] < colSize


def isEmpty(maps, nextPos):
    return maps[nextPos[0]][nextPos[1]] == 1


if __name__ == '__main__':
    maps = [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]
    maps = [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,1]]	
    print(solution(maps))
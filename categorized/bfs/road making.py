# https://programmers.co.kr/learn/courses/30/lessons/67259

# Point1. You must store minimum costs to reach certain point with
# both 2 directions

# Point2. Create Queue, which is ordered by the cost to reach
# and stores the roads with position and direction

# If you've reached the goal for the first time, it must be the minimum
# cost to reach the goal

from collections import defaultdict

def solution(board):
    answer = 0

    boardSize = len(board)
    GOAL = (boardSize - 1, boardSize - 1)
    HORIZONTAL, VERTICAL = 0, 1
    straight, corner = 100, 600

    maxCost = corner * boardSize * boardSize
    minCostsHor = [[maxCost] * boardSize for _ in range(boardSize)]
    minCostsVer = [[maxCost] * boardSize for _ in range(boardSize)]

    queue = defaultdict(list)
    if board[0][1] == 0:
        queue[straight].append([HORIZONTAL, 0, 1])
        minCostsHor[0][1] = 100
    if board[1][0] == 0:
        queue[straight].append([VERTICAL, 1, 0])
        minCostsVer[1][0] = 100

    minCostsHor[0][0], minCostsVer[0][0] = 0, 0

    curCost = 100
    while queue:
        roads = queue[curCost]
        for road in roads:
            dir, row, col = road[:]
            if (row, col) == GOAL:
                return curCost

            if dir == HORIZONTAL:
                if curCost > minCostsHor[row][col] + 500:
                    continue

                if col > 0 and board[row][col - 1] == 0:
                    nextCost = curCost + straight
                    if nextCost < minCostsHor[row][col - 1]:
                        minCostsHor[row][col - 1] = nextCost
                        queue[nextCost].append([HORIZONTAL, row, col - 1])
                
                if col < boardSize - 1 and board[row][col + 1] == 0:
                    nextCost = curCost + straight
                    if nextCost < minCostsHor[row][col + 1]:
                        minCostsHor[row][col + 1] = nextCost
                        queue[nextCost].append([HORIZONTAL, row, col + 1])

                if row > 0 and board[row - 1][col] == 0:
                    nextCost = curCost + corner
                    if nextCost < minCostsVer[row - 1][col]:
                        minCostsVer[row - 1][col] = nextCost
                        queue[nextCost].append([VERTICAL, row - 1, col])
                
                if row < boardSize - 1 and board[row + 1][col] == 0:
                    nextCost = curCost + corner
                    if nextCost < minCostsVer[row + 1][col]:
                        minCostsVer[row + 1][col] = nextCost
                        queue[nextCost].append([VERTICAL, row + 1, col])
            
            else:
                if curCost > minCostsVer[row][col] + 500:
                    continue

                if col > 0 and board[row][col - 1] == 0:
                    nextCost = curCost + corner
                    if nextCost < minCostsHor[row][col - 1]:
                        minCostsHor[row][col - 1] = nextCost
                        queue[nextCost].append([HORIZONTAL, row, col - 1])
                
                if col < boardSize - 1 and board[row][col + 1] == 0:
                    nextCost = curCost + corner
                    if nextCost < minCostsHor[row][col + 1]:
                        minCostsHor[row][col + 1] = nextCost
                        queue[nextCost].append([HORIZONTAL, row, col + 1])

                if row > 0 and board[row - 1][col] == 0:
                    nextCost = curCost + straight
                    if nextCost < minCostsVer[row - 1][col]:
                        minCostsVer[row - 1][col] = nextCost
                        queue[nextCost].append([VERTICAL, row - 1, col])
                
                if row < boardSize - 1 and board[row + 1][col] == 0:
                    nextCost = curCost + straight
                    if nextCost < minCostsVer[row + 1][col]:
                        minCostsVer[row + 1][col] = nextCost
                        queue[nextCost].append([VERTICAL, row + 1, col])

        curCost += 100


    return answer


if __name__ == "__main__":
    board = [[0,0,0],[0,0,0],[0,0,0]]
    print(solution(board))
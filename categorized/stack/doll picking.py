# https://programmers.co.kr/learn/courses/30/lessons/64061?language=python3

# rotate matrix, using zip
# remove 0s
# pop and push

def solution(board, moves):
    board = list(map(list, zip(*board)))

    for column in board:
        for i in range(len(column) - 1, -1, -1):
            if column[i] == 0:
                column.pop(i)


    stack = []
    cnt = 0
    for move in moves:
        move -= 1
        if len(board[move]) > 0:
            top = board[move].pop(0)
            if top > 0:
                if len(stack) == 0:
                    stack.append(top)
                elif stack[-1] == top:
                    stack.pop()
                    cnt += 2
                else:
                    stack.append(top)
    return cnt


if __name__ == "__main__":
    board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]	
    moves = [1,5,3,5,1,2,1,4]	
    print(solution(board, moves))
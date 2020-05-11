def solution(board:[]):
    board_size = len(board)
    Horizontal, Vertical = 0, 1
    que, visited, steps = [(Horizontal, (0, 0))], {(Horizontal, (0, 0))}, 0
    goal = ((Horizontal, (board_size - 1, board_size - 2)), (Vertical, (board_size - 2, board_size - 1)))
    while len(que) != 0:
        next_que = []
        for robot in que:
            if robot in goal:
                return steps
            else:
                # cur_robot is in horizontal shape
                pos, row, col = robot[1], robot[1][0], robot[1][1]
                if robot[0] == Horizontal:
                    # move left or right
                    left_horizontal, right_horizontal = (Horizontal, (row, col - 1)), (Horizontal, (row, col + 1))
                    if col > 0 and board[row][col - 1] == 0 and left_horizontal not in visited:
                        next_que.append(left_horizontal)
                        visited.add(left_horizontal)
                    if col < board_size - 2 and board[row][col + 2] == 0 and right_horizontal not in visited:
                        next_que.append(right_horizontal)
                        visited.add(right_horizontal)

                    # move down or up
                    up_horizontal, down_horizontal = (Horizontal, (row - 1, col)), (Horizontal, (row + 1, col))
                    if row > 0 and board[row - 1][col] == 0 and board[row - 1][col + 1] == 0 and up_horizontal not in visited:
                        next_que.append(up_horizontal)
                        visited.add(up_horizontal)
                    if row < board_size - 1 and board[row + 1][col] == 0 and board[row + 1][col + 1] == 0 and down_horizontal not in visited:
                        next_que.append(down_horizontal)
                        visited.add(down_horizontal)

                    # turn downward
                    if row < board_size - 1 and board[row + 1][col] == 0 and board[row + 1][col + 1] == 0:
                        left_vertical, right_vertical = (Vertical, (row, col)), (Vertical, (row, col + 1))
                        if left_vertical not in visited:
                            next_que.append(left_vertical)
                            visited.add(left_vertical)
                        if right_vertical not in visited:
                            next_que.append(right_vertical)
                            visited.add(right_vertical)
                    
                    # turn upward
                    if row > 0 and board[row - 1][col] == 0 and board[row -1][col + 1] == 0:
                        left_vertical, right_vertical = (Vertical, (row - 1, col)), (Vertical, (row - 1, col + 1))
                        if left_vertical not in visited:
                            next_que.append(left_vertical)
                            visited.add(left_vertical)
                        if right_vertical not in visited:
                            next_que.append(right_vertical)
                            visited.add(right_vertical)

                elif robot[0] == Vertical:
                    # move up or down
                    up_vertical, down_vertical = (Vertical, (row - 1, col)), (Vertical, (row + 1, col))
                    if row > 0 and board[row - 1][col] == 0 and up_vertical not in visited:
                        next_que.append(up_vertical)
                        visited.add(up_vertical)
                    if row < board_size - 2 and board[row + 2][col] == 0 and down_vertical not in visited:
                        next_que.append(down_vertical)
                        visited.add(down_vertical)
                    
                    # move left or right
                    left_vertical, right_vertical = (Vertical, (row, col - 1)), (Vertical, (row, col + 1))
                    if col > 0 and board[row][col - 1] == 0 and board[row + 1][col - 1] == 0 and left_vertical not in visited:
                        next_que.append(left_vertical)
                        visited.add(left_vertical)
                    if col < board_size - 1 and board[row][col + 1] == 0 and board[row + 1][col + 1] == 0 and right_vertical not in visited:
                        next_que.append(right_vertical)
                        visited.add(right_vertical)

                    
                    # turn right
                    if col < board_size - 1 and board[row][col + 1] == 0 and board[row + 1][col + 1] == 0:
                        up_horizontal, down_horizontal = (Horizontal, (row, col)), (Horizontal, (row + 1, col))
                        if up_horizontal not in visited:
                            visited.add(up_horizontal)
                            next_que.append(up_horizontal)
                        if down_horizontal not in visited:
                            visited.add(down_horizontal)
                            next_que.append(down_horizontal)
                    
                    # turn left
                    if col > 0 and board[row][col - 1] == 0 and board[row + 1][col - 1] == 0:
                        up_horizontal, down_horizontal = (Horizontal, (row, col - 1)), (Horizontal, (row + 1, col - 1))
                        if up_horizontal not in visited:
                            visited.add(up_horizontal)
                            next_que.append(up_horizontal)
                        if down_horizontal not in visited:
                            visited.add(down_horizontal)
                            next_que.append(down_horizontal)

        steps += 1
        que = next_que
    return -1

if __name__ == "__main__":
    board = [[0, 0, 0, 1, 1],[0, 0, 0, 1, 0],[0, 1, 0, 1, 1],[1, 1, 0, 0, 1],[0, 0, 0, 0, 0]]
    print(solution(board))
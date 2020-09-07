def solution(numbers, hand):
    answer = ''
    left_pos, right_pos = [0, 0], [2,0]

    for number in numbers:
        if number in [1, 4, 7]:
            answer += "L"
            left_pos = [0, (10 - number) // 3]
        elif number in [3, 6, 9]:
            answer += "R"
            right_pos = [2, (12 - number) // 3]
        elif number in [2, 5, 8]:
            dest = [1, (11 - number) // 3]
            left_dist = distance(left_pos, dest)
            right_dist = distance(right_pos, dest)
            if left_dist == right_dist:
                if hand == "left":
                    answer += "L"
                    left_pos = dest
                else:
                    answer += "R"
                    right_pos = dest
            elif left_dist < right_dist:
                answer += "L"
                left_pos = dest
            else:
                answer += "R"
                right_pos = dest
        else:
            dest = [1, 0]
            left_dist = distance(left_pos, dest)
            right_dist = distance(right_pos, dest)
            if left_dist == right_dist:
                if hand == "left":
                    answer += "L"
                    left_pos = dest
                else:
                    answer += "R"
                    right_pos = dest
            elif left_dist < right_dist:
                answer += "L"
                left_pos = dest
            else:
                answer += "R"
                right_pos = dest
    return answer


def distance(src, dest):
    return abs(src[0] - dest[0]) + abs(src[1] - dest[1])


if __name__ == "__main__":
    numbers = [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]
    numbers = [7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2]
    solution(numbers, "left")
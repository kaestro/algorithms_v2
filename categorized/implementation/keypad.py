# https://programmers.co.kr/learn/courses/30/lessons/67256

def solution(numbers, hand):
    answer = ''
    key_dict = {
        1: (0, 3), 4: (0, 2), 7: (0, 1), '*': (0,0),
        2: (1, 3), 5: (1, 2), 8: (1, 1), 0: (1, 0),
        3: (2, 3), 6: (2, 2), 9: (2, 1), '#': (2, 0)
    }

    left_pos = key_dict['*']
    right_pos = key_dict['#']

    for number in numbers:
        if number in [1, 4, 7]:
            answer += 'L'
            left_pos = key_dict[number]
        elif number in [3, 6, 9]:
            answer += 'R'
            right_pos = key_dict[number]
        else:
            key_pos = key_dict[number]
            left_dist = distance(left_pos, key_pos)
            right_dist = distance(right_pos, key_pos)
            if left_dist < right_dist:
                answer += 'L'
                left_pos = key_dict[number]
            elif left_dist > right_dist:
                answer += 'R'
                right_pos = key_dict[number]
            else:
                if hand == 'left':
                    answer += 'L'
                    left_pos = key_dict[number]
                else:
                    answer += 'R'
                    right_pos = key_dict[number]

    return answer


def distance(src, dst):
    return abs(src[0] - dst[0]) + abs(src[1] - dst[1])
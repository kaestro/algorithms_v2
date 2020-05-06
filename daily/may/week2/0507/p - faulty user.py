import re
import copy
from collections import Counter


def backtrack(user_ids, banned_ids, idx, bannable_ids:{}, cur: [], answer:[]):
    if idx == len(banned_ids):
        answer.append(cur)
        return

    banned_id = banned_ids[idx]
    idx += 1

    for i in range(len(bannable_ids[banned_id])):
        temp = bannable_ids[banned_id][i]
        next = copy.deepcopy(cur)
        next.append(temp)
        next.sort()

        copy_bannable_ids = copy.deepcopy(bannable_ids)
        for key in copy_bannable_ids.keys():
            if temp in copy_bannable_ids[key]:
                copy_bannable_ids[key].remove(temp)

        backtrack(user_ids, banned_ids, idx, copy_bannable_ids, next, answer)


def solution(user_ids, banned_ids):
    answer = 1
    bannable_ids = {banned_id : [] for banned_id in banned_ids}
    for banned_id in set(banned_ids):
        pattern_string = '^'
        for c in banned_id:
            if c == '*':
                pattern_string += '.'
            else:
                pattern_string += c
        pattern_string += '$'
        for user_id in user_ids:
            if re.search(pattern_string, user_id) is not None:
                bannable_ids[banned_id].append(user_id)
    
    cur, answer = [], []
    backtrack(user_ids, banned_ids, 0, bannable_ids, cur, answer)

    result = set()

    for line in answer:
        result.add(''.join(line))
    return len(result)

if __name__ == "__main__":
    user_ids = 	["frodo", "fradi", "crodo", "abc123", "frodoc"]
    banned_ids = ["*rodo", "*rodo", "******"]
    solution(user_ids, banned_ids)
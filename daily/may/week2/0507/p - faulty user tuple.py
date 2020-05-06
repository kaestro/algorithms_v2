import re

def backtrack(user_ids:[], ban_ids:[], idx:int, banned_ids:set, cur:[]):
    if idx == len(ban_ids):
        banned_ids.add(tuple(user_id for user_id in sorted(cur)))
        return

    pattern = '^'
    for c in ban_ids[idx]:
        if c == '*': pattern += '.'
        else: pattern += c
    pattern += '$'

    idx += 1
    for i in range(len(user_ids)):
        user_id = user_ids[i]
        if re.search(pattern, user_id) is not None:
            cur.append(user_id)
            user_ids.pop(i)
            backtrack(user_ids, ban_ids, idx, banned_ids, cur)
            cur.pop()
            user_ids.insert(i, user_id)


def solution(user_ids, ban_ids):
    banned_ids = set()
    backtrack(user_ids, ban_ids, 0,banned_ids, [])
    return len(banned_ids)


if __name__ == "__main__":
    user_ids = 	["frodo", "fradi", "crodo", "abc123", "frodoc"]
    banned_ids = ["*rodo", "*rodo", "******"]
    solution(user_ids, banned_ids)
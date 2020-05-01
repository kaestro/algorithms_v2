import itertools

def solution(relations):
    answer = 0
    length = 1
    key_cnt = len(relations[0])
    tuples_used, idx_unused = [], [i for i in range(key_cnt)]

    L = 1
    while L <= len(idx_unused):
        plus_used = set()
        for idxes in itertools.combinations(idx_unused, L):
            idxes = set(idxes)
            used_tuple = False
            for tuple_used in tuples_used:
                if tuple_used == tuple_used & idxes:
                    used_tuple = True
                    break

            if used_tuple: continue

            occupied = []
            for relation in relations:
                element = [relation[idx] for idx in idxes]
                if element in occupied: break
                else: occupied.append(element)

            if len(occupied) == len(relations):
                answer += 1
                tuples_used.append(idxes)

        L += 1
    return answer


if __name__ == "__main__":
    relation = [["100","ryan","music","2"],["200","apeach","math","2"],
            ["300","tube","computer","3"],["400","con","computer","4"],
            ["500","muzi","music","3"],["600","apeach","music","2"]]
    solution(relation)
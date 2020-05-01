import itertools

def solution(relation :[]) -> int:
    answer = []
    key_cnt, rel_cnt = len(relation[0]), len(relation)
    idxes = [i for i in range(key_cnt)]

    for L in range(1, key_cnt + 1):
        for tup in itertools.combinations(idxes, L):
            tup = set(tup)

            # minimality check
            isMinimal = False
            for ans_tup in answer:
                if ans_tup == ans_tup & tup:
                    isMinimal = True
                    break
            if isMinimal: continue

            # check uniqueness
            elements = []
            for row in relation:
                element = [row[i] for i in tup]
                if element in elements: break
                else: elements.append(element)
            if len(elements) == rel_cnt: answer.append(tup)

    return len(answer)


if __name__ == "__main__":
    relation = [["100","ryan","music","2"],["200","apeach","math","2"],
                ["300","tube","computer","3"],["400","con","computer","4"],
                ["500","muzi","music","3"],["600","apeach","music","2"]]	
    print(solution(relation))
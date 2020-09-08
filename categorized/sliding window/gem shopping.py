# https://programmers.co.kr/learn/courses/30/lessons/67258

def solution(gems):
    answer, ansLen = [0, len(gems)], len(gems)
    gemCategory = set(gems)
    gemCnt = {gemIdx : 0 for gemIdx in gemCategory}
    maxGemKindCnt = len(gemCategory)

    startIdx, gemKindCnt = 0, 0
    for idx, gem in enumerate(gems):
        gemCnt[gem] += 1
        if gemCnt[gem] == 1:
            gemKindCnt += 1
            if gemKindCnt == maxGemKindCnt:
                endIdx = idx
                while gemKindCnt == maxGemKindCnt:
                    curLen = endIdx - startIdx + 1
                    if ansLen > curLen:
                        answer, ansLen = [startIdx + 1, endIdx + 1], curLen
                    gemCnt[gems[startIdx]] -= 1
                    if gemCnt[gems[startIdx]] == 0:
                        gemKindCnt -= 1
                    startIdx += 1

    return [answer[0] + 1, answer[1] + 1]


if __name__ == "__main__":
    gems = ["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]
    print(solution(gems))
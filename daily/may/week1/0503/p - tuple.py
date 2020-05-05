import re
import collections

def solution(s):
    num_cnt = collections.Counter(map(int, re.findall('\d+', s)))
    answer = [key for key, val in sorted(num_cnt.items(), key = lambda x : x[1], reverse=True)]
    return answer

if __name__ == "__main__":
    print(solution("\{\{2\},\{2,1\},\{2,1,3\},\{2,1,3,4\}\}"))
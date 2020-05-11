import re

def solution(lines:[])->int:
    answer = 0
    times = []
    for line in lines:
        start = list(map(int, re.findall("(\d\d):(\d\d):(\d\d).(\d\d\d)", line)[0]))
        start = (start[0] * 3600 + start[1] * 60 + start[2]) * 1000 + start[3]
        durat = list(map(int, re.findall("(\d).(\d{0,3})s", line)[0]))
        durat = durat[0] * 1000 + durat[1]
        continue

    return answer


if __name__ == "__main__":
    lines = [
        "2016-09-15 20:59:57.421 0.351s",
        "2016-09-15 20:59:58.233 1.181s",
        "2016-09-15 20:59:58.299 0.8s",
        "2016-09-15 20:59:58.688 1.041s",
        "2016-09-15 20:59:59.591 1.412s",
        "2016-09-15 21:00:00.464 1.466s",
        "2016-09-15 21:00:00.741 1.581s",
        "2016-09-15 21:00:00.748 2.31s",
        "2016-09-15 21:00:00.966 0.381s",
        "2016-09-15 21:00:02.066 2.62s"
    ]
    solution(lines)
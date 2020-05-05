from collections import Counter

def solution(N, stages):
    answer = []
    stages = Counter(stages)
    total_users = sum(stages.values())
    stages = list(sorted(stages.items(), key = lambda x : x[0]))

    failure_rates = {i : 0 for i in range(1, N + 1)}
    for stage, num_users in stages:
        if (stage >= N + 1): break
        failure_rates[stage] = num_users / total_users
        total_users -= num_users

    return list(key for key, val in sorted(failure_rates.items(), key = lambda x : x[1], reverse = True))


if __name__ == "__main__":
    stages = [2, 1, 2, 6, 2, 4, 3, 3]
    N = 5
    print(solution(N, stages))
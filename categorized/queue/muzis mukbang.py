# https://programmers.co.kr/learn/courses/30/lessons/42891
# algorithm: queue
# date: 09.12.2020

def solution(food_times, k):
    answer = 0
    foodLen = len(food_times)
    totalFood = sum(food_times)
    foodIdx = 0
    queue = [[i, food_time] for i, food_time in  enumerate(food_times)]
    for _ in range(k):
        queue[foodIdx][1] -= 1
        totalFood -= 1
        if totalFood == 0:
            return -1
        if queue[foodIdx][1] == 0:
            queue.pop(foodIdx)
            foodLen -= 1
        else:
            foodIdx += 1
        foodIdx %= foodLen 

    return queue[foodIdx][0] + 1


if __name__ == "__main__":
    food_times = [3, 1, 2]
    k = 5
    print(solution(food_times, k))
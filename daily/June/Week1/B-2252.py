def Solution():
    numStudents, numCompares = map(int, input().split())
    Graph = [[] for _ in range(numStudents + 1)]
    numTaller = [0 for _ in range(numStudents + 1)]
    for _ in range(numCompares):
        taller, shorter = map(int, input().split())

        Graph[taller].append(shorter)
        numTaller[shorter] += 1
    
    order = [student for student in range(1, numStudents + 1) if numTaller[student] == 0]
    for student in order:
        for shorter in Graph[student]:
            numTaller[shorter] -= 1
            if numTaller[shorter] == 0:
                order.append(shorter)
    
    print(order)


if __name__ == "__main__":
    Solution()

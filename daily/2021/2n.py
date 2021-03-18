def solution(n):
    lst = []
    for i in range(1, n+1):
        if i == 1:
            lst.append(1)
        elif i == 2:
            lst.append(2)
        else:
            lst.append(lst[-1] + lst[-2])
    return lst[-1]
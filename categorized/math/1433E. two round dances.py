import math


if __name__ == "__main__":
    num = int(input())
    comb = math.factorial(num) // math.factorial(num // 2) // math.factorial(num // 2)
    res = comb * (math.factorial(num // 2 - 1) ** 2)
    res = res // 2
    print(res)
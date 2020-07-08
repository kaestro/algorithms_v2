# https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0

if __name__ == "__main__":
    num_testcase = int(input())
    for _ in range(num_testcase):
        n = int(input())
        ans = -1
        while n > 0:
            ans += n % 3
            ans += (n > 2)
            n //= 3
        print(ans)
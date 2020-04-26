def get_gcd(lhs, rhs) -> int:
    if lhs < rhs:
        lhs, rhs = rhs, lhs
        
    while True:
        temp = lhs % rhs
        
        if temp == 0:
            break
        else:
            lhs, rhs = rhs, temp
    return rhs

def solution(nums):
    answer = 1
    for num in nums:
        gcd = get_gcd(num, answer)
        answer *= num // gcd

    return answer

if __name__ == "__main__":
    nums = [2,6,8,14]	
    ans = solution(nums)